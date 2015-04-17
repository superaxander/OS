#ifndef __VGA_H__
#define __VGA_H__ 1
#include <stddef.h>
size_t VGA_WIDTH = 80;
size_t VGA_HEIGHT = 25;

uint16_t* VGA_MEMORY = (uint16_t*) 0xB8000;

uint8_t make_color(uint8_t fg, uint8_t bg);
uint16_t make_vgaentry(char c, uint8_t color);

#endif