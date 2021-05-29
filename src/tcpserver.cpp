#include "tcpserver.h"
//todo: clean up header management between tcpserver.cpp and .h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//error wrapper
void error(const char *msg){
    perror(msg);
    exit(1);
}

//basically just sets the port
//the rest of what we'll need will be calculated in TcpServer::init()
TcpServer::TcpServer(int portno) {
   
   if(portno < 49153 || portno > 65535)
      error("ERROR invalid port");
   
   this->port = portno;
   
}

//creates and binds to a socket, assigns values to necessary data members
void TcpServer::init() {
   
   // open a new socket
   this->sockfd =  socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) 
      error("ERROR opening socket");
   
   // clear address structure
   // (bzero replaces any data with '\0' starting at the ptr to a length of the size of the data)
   bzero((char *) &(this->serv_addr), sizeof(this->serv_addr));
   
   this->serv_addr.sin_family = AF_INET; // set ipv4 (todo: config file)
   this->serv_addr.sin_addr.s_addr = INADDR_ANY; // set as current ip
   this->serv_addr.sin_port = htons(this->port); // convert to network byte order, set as port for serv_addr
   
   //bind and check if successful
   if (bind(this->sockfd, (struct sockaddr *) &(this->serv_addr), sizeof(this->serv_addr)) < 0) 
      error("ERROR on binding");
   
}

void TcpServer::readin(char* buffer, int BUF_SIZE) {
   
   socklen_t clilen = sizeof(cli_addr); // it doesn't work unless i do this (???)
   int newsockfd; // new socket file descriptor solely for reading data
   bzero(buffer, BUF_SIZE); // clear buffer
   
   //check if port isn't bound or created yet
   if(this->sockfd < 0)
      error("ERROR use TcpServer::init() before attempting to read in data");
   
   listen(this->sockfd,5); // listen on port (todo: make backlog count configurable)
   newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); // accept returns a new file descriptor to use and close
   
   printf("server: got connection from %s port %d\n", inet_ntoa(this->cli_addr.sin_addr), ntohs(this->cli_addr.sin_port));
   if (read(newsockfd, buffer, BUF_SIZE-1) < 0) // read data and error check
      error("ERROR reading from socket");
      
   close(newsockfd);
}

void TcpServer::closesock() { close(this->sockfd); }

