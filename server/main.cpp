#include <iostream>
#include <unistd.h>
#include <thread>

#include "TcpServer.h"
#include "../common/Socket.h"

void doStuff(client_server_app::TcpSocket newSocket, int clientId)
{
    std::string data{};
    while (data != "42")
    {
        data = newSocket.read().data;
        std::cout << "message from client " + std::to_string(clientId) + ": " + data
            << '\n';
        std::string response{ "server received: " + data };
        newSocket.write(response);
    }
}

int main()
{
    int port = 5555;
    client_server_app::TcpServer server{ port };
    std::cout << "server running on port " << port << '\n';

    int clientId{ 1 };

    while (true)
    {
        client_server_app::TcpSocket newSocket{ server.accept() };

        std::thread thread{ doStuff, std::move(newSocket), clientId++ };
        thread.detach();
    }

    return 0;
}
