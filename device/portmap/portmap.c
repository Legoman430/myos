#include "portmap.h"

//Function that runs assembly to recieve input from a specified port
uint8_t inb(uint16_t port) {

     uint8_t ret;

     __asm__ __volatile__("inb %1, %0":"=a"(ret):"Nd"(port));

     return ret;

}

 
//function that runs assembly that sends a value to a specific port
void outb(uint16_t port, uint8_t val) {

     __asm__ __volatile__("outb %0, %1": : "a" (val), "Nd" (port));

}

