#include<iostream>
#include<string>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
void check_error(bool test, std::string error_message);
int create_socket();
