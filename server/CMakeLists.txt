add_executable(server TcpServer.cpp main.cpp)

target_link_libraries(server PRIVATE common)
