#ifndef CLIENT_SERVER_APP_ADDRESS_DOMAIN_H_
#define CLIENT_SERVER_APP_ADDRESS_DOMAIN_H_

#include <sys/socket.h>

enum class AddressDomain
{
    kInternetDomain = AF_INET,
    kUnixDomain = AF_UNIX
};

#endif
