#include "TcpServer.h"

#include <iostream>

namespace client_server_app
{
TcpServer::TcpServer(int port)
{
    // probably a good idea to move exceptions to constructors here
    // instead of having them in the socket itself
    bool bound{ m_socket.bind(port) };
    if (!bound)
    {
        throw std::runtime_error{ "server not bound" };
    }

    // maybe do this elsewhere? kinda confusing tbh
    bool listening{ m_socket.listen() };

    if (!listening)
    {
        throw std::runtime_error{ "server not listening" };
    }
}

TcpSocket TcpServer::accept()
{
    auto socket{ m_socket.accept() };
    if (!socket)
    {
        throw std::runtime_error{ "tcpserver::accept error" };
    }

    return socket.value();
}

std::string TcpServer::read()
{
    // throws i guess
    // we dont really need the bytesRead thing i suppose
    auto [bytesRead, data]{ m_socket.read() };

    std::cout << "bytes read: " << bytesRead << '\n';

    return data;
}

void TcpServer::write(const std::string& data)
{
    m_socket.write(data);
}
}
