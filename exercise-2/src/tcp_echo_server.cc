#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

const int kBufferSize = 1024;
//I realized during my refactoring that I deleted the question. While it is there in a previous commit, I will type my answer here
//Yes, while true is necessary to keep the server alive. It is not very inefficient because accept is a blocking call, meaning cpu wont be doing any work until accept gets a message.

int setup_socket(int kport){

  sockaddr_in address;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(kport);
  address.sin_family = AF_INET;

  int sockfd;
  if((sockfd=socket(AF_INET, SOCK_STREAM, 0))<0){
    std::cerr<<"Socket creation failed";
    exit(EXIT_FAILURE);
  }
  int socket_options = 1;
  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &socket_options, sizeof(socket_options))<0){
    std::cerr << "Socket options failed";
    exit(EXIT_FAILURE);
  }

  if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &socket_options, sizeof(socket_options))<0){
    std::cerr << "Socket options failed";
    exit(EXIT_FAILURE);
  }


  if(bind(sockfd,(struct sockaddr *)&address, sizeof(address))<0){
    std::cerr << "Binding failed";
    exit(EXIT_FAILURE);
  }

  if(listen(sockfd, 3)<0){
     std::cerr << "Listening failed";
    exit(EXIT_FAILURE);
  }
  std::cout<<"Server listening on port " << kport << std::endl;

  return sockfd;
}


//accepts new users and receives data from them as well
void handle_socket(int sock_fd){
  while(true){
    sockaddr_storage connection;
    socklen_t size = sizeof(connection);
    int new_socket = accept(sock_fd, (sockaddr *) &connection, &size);

    if(new_socket<0){
      std::cerr<< "Error with accepted socket";
      continue;
    }


    char buffer[kBufferSize]={0};
    ssize_t received_data = recv(new_socket, buffer, kBufferSize, 0);
    if(received_data>0){
       std::cout << "Received: " << buffer << "\n";
       send(new_socket, buffer, received_data, 0); 
       std::cout << "Echo message sent\n";
    }
    else if (received_data == 0) {
     std::cout << "Client disconnected.\n";
     } else {
       std::cerr << "Read error on client socket " << new_socket << "\n";
   }
    close(new_socket);
  }

}

int main(){
  int port = 8080;
  int my_socket = setup_socket(port);
  handle_socket(my_socket);
  close(my_socket);



  return 0;
}