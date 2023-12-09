#include "console.h"
#include "keyboard.h"
#include <stdint.h>
#include "io.h"

//main function
void main() {

//clear the terminal
clear_terminal();
clear_terminal();

//byte to store user input
uint8_t byte;

//main loop
while(1) {

    //if the user entered a value, display it
     while ( byte = scan()) {
        print_character(charmap[byte]);
    }
}

}