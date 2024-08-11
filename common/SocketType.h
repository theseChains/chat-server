#ifndef CLIENT_SERVER_APP_SOCKET_TYPE_H_
#define CLIENT_SERVER_APP_SOCKET_TYPE_H_

#include <sys/socket.h>

namespace client_server_app
{
enum class SocketType
{
    kTcpSocket = SOCK_STREAM,
    kUdpSocket = SOCK_DGRAM
};
}

#endif
