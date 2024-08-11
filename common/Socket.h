#ifndef CLIENT_SERVER_APP_TCP_SOCKET_H_
#define CLIENT_SERVER_APP_TCP_SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <optional>
#include <string>

#include "AddressDomain.h"
#include "ReadResult.h"
#include "SocketType.h"

namespace client_server_app
{
class TcpSocket
{
public:
    TcpSocket();

    bool bind(int port);
    bool listen() const;
    std::optional<TcpSocket> accept();

    bool connect(const std::string& host, int port);

    ReadResult read();
    long int write(const std::string& data);

private:
    int m_socketDescriptor{};
    sockaddr_in m_address{};
};
}

#endif
