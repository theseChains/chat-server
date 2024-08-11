#include "TcpClient.h"

#include <iostream>

namespace client_server_app
{
TcpClient::TcpClient(const std::string& host, int port)
{
    m_socket.connect(host, port);

    std::cout << "client connected to host " << host << '\n';
}

std::string TcpClient::read()
{
    // throws i guess
    // we dont really need the bytesRead thing i suppose
    auto [bytesRead, data]{ m_socket.read() };

    std::cout << "bytes read: " << bytesRead << '\n';

    return data;
}

void TcpClient::write(const std::string& data)
{
    m_socket.write(data);
}
}
