//File header for io operations
#ifndef PORTMAP_H
#define PORTMAP_H
#include <stdint.h>

//declaration for io functions
uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);

#endif
