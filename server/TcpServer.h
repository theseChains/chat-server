#ifndef CLIENT_SERVER_APP_TCP_SERVER_H_
#define CLIENT_SERVER_APP_TCP_SERVER_H_

#include "../common/Socket.h"

namespace client_server_app
{
class TcpServer
{
public:
    TcpServer(int port);

    TcpSocket accept();
    
    std::string read();
    void write(const std::string& data);

private:
    TcpSocket m_socket{};
};
}

#endif
