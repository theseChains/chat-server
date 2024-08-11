#ifndef CLIENT_SERVER_APP_TCP_CLIENT_H_
#define CLIENT_SERVER_APP_TCP_CLIENT_H_

#include "../common/Socket.h"

#include <string>

namespace client_server_app
{
class TcpClient
{
public:
    TcpClient(const std::string& host, int port);

    std::string read();
    void write(const std::string& data);

private:
    TcpSocket m_socket{};
};
}

#endif
