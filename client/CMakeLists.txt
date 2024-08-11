add_executable(client TcpClient.cpp main.cpp)

target_link_libraries(client PRIVATE common)
