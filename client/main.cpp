#include <iostream>

#include "../common/Socket.h"
#include "TcpClient.h"

int main()
{
    int port = 5555;
    client_server_app::TcpClient client{ "127.0.0.1", port };

    std::string reply{};

    try
    {
        std::string message{};
        while (message != "42")
        {
            std::cout << "enter message for server: ";
            std::cin >> message;
            client.write(message);
            reply = client.read();
            std::cout << reply << '\n';
        }
    }
    catch (...)
    {
        std::cout << "better catch it!";
    }

    return 0;
}
