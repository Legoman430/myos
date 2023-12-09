//Function headers for various console display functions
#ifndef MYOS_INCLUDE_CONSOLE_H
#define MYOS_INCLUDE_CONSOLE_H

//CONSTANTS for console display
static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;
static const int VGA_BYTES_PER_CHARACTER=2;

//color map
typedef enum {
BLACK=0,
BLUE,
GREEN,
CYAN,
RED,
MAGENTA,
BROWN,
LIGHT_GRAY,
DARK_GRAY,
LIGHT_BLUE,
LIGHT_GREEN,
LIGHT_CYAN,
LIGHT_RED,
LIGHT_MAGENTA,
YELLOW,
WHITE
} VGA_Color;

//Function declaration for various console displays 
void clear_terminal();
void print_character_with_color(char c, VGA_Color bg_color, VGA_Color font_color);
void print_string_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void print_line_with_color(char* str, VGA_Color bg_color, VGA_Color font_color);
void print_character(char c);
void print_string(char* str);
void print_line(char* str);
void set_terminal_font_color(VGA_Color col);
void set_terminal_background_color(VGA_Color col);
int my_ceil(float x);

#endif
