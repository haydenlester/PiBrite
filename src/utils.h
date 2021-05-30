#ifndef utils
#define utils
#include <string>

// error wrapper
void error(const char *msg);

//notification struct
struct notification {
   
   std::string source;
   std::string shortdesc;
   std::string desc;
   
};

//done untested
//converts an xml string to a notification structure
struct notification toNotification(std::string notif);

#endif