#ifndef tcpserver
#define tcpserver

#include <netinet/in.h>
#include <string>

class TcpServer{
   
   public:
   TcpServer(int port);          // constructor (port no must always be specified)
                                 // destructor is default
   void init();                  // init TcpServer (create, bind)
   void closesock();             // closes TcpServer
   void readin(char* buffer, int BUF_SIZE);  // read in data (listen, accept, read) returns xml string

   private:
   int sockfd; // socket file descriptor for listening
   int port;   // the port to communicate on
   
   /*
   this struct holds some connection info, imported from netinet/in.h
   */
   struct sockaddr_in serv_addr, cli_addr;
   
};

#endif