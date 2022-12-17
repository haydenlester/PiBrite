# PiBrite
A notification program for Raspberry Pi's to display notifications to a character-based LCD.

## How do I use it?
*Currently only the TCP server functions properly. I may return to this later.*

todos:
- a diagram for GPIO connections
- a standard format for notifications using XML
- information on configuring the server
- information on the tcpserver class
- makefile

usage:
1) download repo and make using makefile
2) connect correct gpio headers to correct lcd headers
2) execute program with one argument for port number

from there, tcp data can be sent to the address and the notification will display itself on the lcd. currently, it will only support one xml format, of which a template will be given. you can program your own clients to send notifications to the pi, or use a default one which will be developed later and linked here
