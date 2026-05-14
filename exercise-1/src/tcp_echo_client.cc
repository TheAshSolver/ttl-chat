#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  // #Question - are these the same type?
  // Not all the data types below are of the same type if that was the question, If that wasn't well, std::string and C stringd are not the same data type as std::string is an implementation of a class while C style strings are arrays of chars
  std::string message = argv[1];
  const int kPort = 8080;
  const std::string kServerAddress = "127.0.0.1";
  sockaddr_in address;
  const int kBufferSize = 1024;
  char buffer[kBufferSize] = {0};
  // Creating socket file descriptor
  int my_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (my_sock < 0) {
    std::cerr << "Socket creation erron\n";
    return -1;
  }
  address.sin_family = AF_INET;
  address.sin_port = htons(kPort);
  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {
    std::cerr << "Invalid address/ Address not supported\n";
    return -1;
  }
  // Connect to the server
  if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "Connection Failed\n";
    return -1;
  }
  // Send message
  send(my_sock, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";
  // Wait for reply
  ssize_t read_size = read(my_sock, buffer, kBufferSize);
  std::cout << "Received: " << buffer << "\n";
  // Close the socket
  close(my_sock);
  return 0;
}