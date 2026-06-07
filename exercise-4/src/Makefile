CXX := g++
CXXFLAGS := -Wall -Wextra 
CLIENT := tcp_echo_client.cpp 
SERVER := tcp_echo_server.cpp
UTILITY := networking.cc
.PHONY: all
all: client server
client: $(CLIENT) $(UTILITY)
		$(CXX) $(CXXFLAGS) $(CLIENT) $(UTILITY) -o client.o
server: $(SERVER) $(UTILITY)
	$(CXX) $(CXXFLAGS) $(SERVER) $(UTILITY) -o server.o
