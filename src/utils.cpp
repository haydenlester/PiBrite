#include "utils.h"
#include <stdlib.h>
#include <string.h>

//error wrapper
void error(const char *msg){
    perror(msg);
    exit(1);
}

struct notification toNotification(std::string notif){
   
   struct notification result;
   unsigned int first, last;
   
   first = notif.find("<source>");
   last = notif.find("</source>");
   result.source = notif.substr(first, last-first);
   
   first = notif.find("<shortdesc>");
   last = notif.find("</shortdesc>");
   result.shortdesc = notif.substr(first, last-first);
   
   first = notif.find("<desc>");
   last = notif.find("</desc>");
   result.desc = notif.substr(first, last-first);
   
   return result;
   
}