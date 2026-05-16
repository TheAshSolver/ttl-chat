CXX=g++
all: client server
SRC=src
BLD=build


client: $(SRC)/tcp_echo_client.cc 
	mkdir -p $(BLD)
	$(CXX) $^ -o $(BLD)/client
server: $(SRC)/tcp_echo_server.cc
	mkdir -p $(BLD)
	$(CXX) $^ -o $(BLD)/server

.PHONY: clean
clean:
	rm -rf $(BLD)