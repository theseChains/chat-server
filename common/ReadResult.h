#ifndef CLIENT_SERVER_APP_READ_RESULT_H_
#define CLIENT_SERVER_APP_READ_RESULT_H_

#include <string>

struct ReadResult
{
    int bytesRead;
    std::string data;
};

#endif
