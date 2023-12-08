#include "console.h"
#include "portmap.h"

//Harrison Kane
char* const VGA_BUFFER = (char*) 0xb8000; 

VGA_Color terminal_font_color = LIGHT_GRAY; 

VGA_Color terminal_background_color = BLACK; 

int terminal_position = 0; 

void update_cursor() {

     uint16_t cursor_position = terminal_position >> 1;

     outb(0x3D4, 0x0F);

     outb(0x3D5, (uint8_t) (cursor_position));

     outb(0x3D4, 0x0E);

     outb(0x3D5, (uint8_t) (cursor_position >> 8));

}



void clear_terminal() {

     for (int i=0; i < VGA_HEIGHT*VGA_WIDTH*VGA_BYTES_PER_CHARACTER; i+=2) { // for every character

                   VGA_BUFFER[i] = 0;

                   VGA_BUFFER[i+1] = LIGHT_GRAY; 

     }
 		update_cursor();
}

void set_terminal_font_color(VGA_Color col) {

     terminal_font_color = col;

}

void set_terminal_background_color(VGA_Color col) {

     terminal_background_color = col;

}

void print_character(char c) {

     print_character_with_color(c, terminal_background_color, terminal_font_color);

}

void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {

      print_string_with_color(str, bg_color, font_color);

      print_character_with_color('\n', bg_color, font_color);

}


void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color) {

     for (int i=0; str[i] != '\0'; i++) {

            print_character_with_color(str[i], bg_color, font_color);

     }

}

void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color) {

       if (c == '\n') {
		
	       //Created a function called my_ceil to mimic math.h ceil
	       terminal_position =  my_ceil(terminal_position/160) * 160;		 
		 update_cursor();
                  return;

         }
          VGA_BUFFER[terminal_position++] = c;

          VGA_BUFFER[terminal_position++] =  (bg_color << 4) | font_color;
	  update_cursor();
return;

}

void print_string(char* str){
for (int i=0; str[i] != '\0'; i++) {

            print_character(str[i]);

     }

	return;

}

void print_line(char* str){
     print_string(str);

      print_character('\n');

	return;
}

//Created my_ceil to mimic math.h ceil function
int my_ceil(float x) {
    if (x >= 0) {

        // If the number is positive or zero, round up to the nearest integer
        return (int)(x + 0.9999999999999f);

    } else {

        // If the number is negative, round to the nearest integer
        return (int)(x);
    }
}


