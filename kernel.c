#include "console.h"
#include "keyboard.h"
#include <stdint.h>
#include "io.h"

/*
void clear_terminal() {
	uint16_t* video_memory = (uint16_t*)0xB8000;

    for (int i = 0; i < 13000; i++) {
        video_memory[i] = (uint16_t)('\0' | (0x07 << 8));
    }
}
*/
void main() {
clear_terminal();
clear_terminal();

uint8_t byte;

while(1) {

     while ( byte = scan()) {

          print_character(charmap[byte]);

     }

}

}



/*
	char* const VGA_BUFFER = (char*) 0xb8000;
	char* str = "";

	for (int i=0; str[i] != '\0'; i++) {
		VGA_BUFFER[i*2] = str[i];
	}



clear_terminal();
set_terminal_font_color(BLACK);

set_terminal_background_color(LIGHT_GREEN);
print_character_with_color('v', BLUE, LIGHT_MAGENTA);

print_string_with_color("HARRISON KANE", LIGHT_CYAN, RED);

print_line_with_color("Operating Systems CS 04390", LIGHT_GREEN, WHITE);

print_character('H');

print_string("Hello Professor");

print_line("Happy Thanksgiving!");



     print_string_with_color("John Mayor", YELLOW, CYAN);

     print_line_with_color("Bruno Mars", MAGENTA, GREEN);

     print_string("The Beatles");

    

*/

//#include <stdint.h>
//uint16_t* video_memory = (uint16_t*)0xB8000;
// Function to clear the screen by writing null characters to visual bytes and 0x07 to style bytes
//void clear_terminal() {
//    for (int i = 0; i < 13000; i++) {
//        video_memory[i] = (uint16_t)('\0' | (0x07 << 8));
//    }
//}
/*
int main() {
    // Clear the screen first
    clear_terminal();

    // Print "Hello World" to the cleared screen
    char* hello = "Hello World";
    int offset = 0;
    for (int i = 0; hello[i] != '\0'; i++) {
        //video_memory[offset] = (uint16_t)(hello[i] | (0x07 << 8));
        offset++;
    }

    // Your kernel code continues here

    while (1) {
        // Your main loop or kernel code
    }

    return 0;
}
*/
