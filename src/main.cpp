/*
$$$$$$$\  $$\ $$$$$$$\            $$\   $$\               
$$  __$$\ \__|$$  __$$\           \__|  $$ |              
$$ |  $$ |$$\ $$ |  $$ | $$$$$$\  $$\ $$$$$$\    $$$$$$\  
$$$$$$$  |$$ |$$$$$$$\ |$$  __$$\ $$ |\_$$  _|  $$  __$$\ 
$$  ____/ $$ |$$  __$$\ $$ |  \__|$$ |  $$ |    $$$$$$$$ |
$$ |      $$ |$$ |  $$ |$$ |      $$ |  $$ |$$\ $$   ____|
$$ |      $$ |$$$$$$$  |$$ |      $$ |  \$$$$  |\$$$$$$$\ 
\__|      \__|\_______/ \__|      \__|   \____/  \_______|
*/
/* Description -------------------------------------------
   
   A Pi-Based LCD Notification Program
   
*/
/* Status ------------------------------------------------

   In Development

   TODO:
         - testing tcpserver.cpp
         - xml parsing
         - > decide a standard format for notifs first
         - lcd handler class
         - More to be added as subtasks arrive...

*/
/* More information --------------------------------------
   
   repo: github.com/sneekr-a/PiBrite
   
   contributors:
   sneekr/HL
   
*/

int main (int argc, char *argv[]) {
   
   while(true) {
      
      // TCP Server Listens and Returns Data
      
      // Data is converted to xml, parsed, and returns a notification object
      
      // Data is written onto LCD with PIGPIO
      // -> LCD display functions use separate LCD handling library (intended for cross-project usage)
      
   }
   
   return 0;
}
