#include "Socket.h"

#include <unistd.h>
#include <iostream>
#include <stdexcept>

#include "Constants.h"

namespace client_server_app
{
TcpSocket::TcpSocket()
{
    m_socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (m_socketDescriptor < 0)
    {
        throw std::runtime_error{ "socket couldn't be created" };
    }
}

bool TcpSocket::bind(int port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(port);

    int result{ ::bind(m_socketDescriptor, reinterpret_cast<sockaddr*>(&m_address),
                       sizeof(m_address)) };

    if (result < 0)
    {
        return false;
    }

    return true;
}

bool TcpSocket::connect(const std::string& host, int port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);

    int status{ inet_pton(AF_INET, host.c_str(), &m_address.sin_addr) };

    if (status <= 0)
    {
        if (status == 0)
        {
            std::cerr << "Invalid IP address format" << std::endl;
        }
        else
        {
            std::cerr << "inet_pton error" << std::endl;
        }

        return false;
    }

    status = ::connect(m_socketDescriptor,
                       reinterpret_cast<sockaddr*>(&m_address),
                       sizeof(m_address));

    if (status < 0)
    {
        std::cerr << "unable to connect to host: " << host << '\n';
        return false;
    }

    return true;
}

bool TcpSocket::listen() const
{
    if (m_socketDescriptor < 0)
    {
        return false;
    }

    int status{ ::listen(m_socketDescriptor, constants::kMaxConnections) };

    if (status < 0)
    {
        return false;
    }

    return true;
}

std::optional<TcpSocket> TcpSocket::accept()
{
    TcpSocket newSocket{};
    
    socklen_t addressLength{ sizeof(m_address) };
    newSocket.m_socketDescriptor = ::accept(m_socketDescriptor,
                                            reinterpret_cast<sockaddr*>(&m_address),
                                            &addressLength);

    if (newSocket.m_socketDescriptor < 0)
    {
        return std::nullopt;
    }

    return std::make_optional<TcpSocket>(newSocket);
}

ReadResult TcpSocket::read()
{
    ReadResult result{};

    char readBuffer[constants::kMaxReadBuffer]{};

    result.bytesRead = ::read(m_socketDescriptor, readBuffer, constants::kMaxReadBuffer);

    if (result.bytesRead < 0)
    {
        throw std::runtime_error{ "coudln't read data from socket" };
    }

    result.data = readBuffer;

    return result;
}

long int TcpSocket::write(const std::string& data)
{
    long int bytesRead{ ::write(m_socketDescriptor, data.c_str(), data.size()) };

    if (bytesRead < 0)
    {
        throw std::runtime_error{ "coudln't write data" };
    }

    return bytesRead;
}
}
