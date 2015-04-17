#include <stddef.h>
#include <stdint.h>
#include "../include/tty.h"
#include "../include/graphics.h"

void drawBox(size_t minX, size_t minY, size_t  maxX, size_t maxY, enum vga_color fg, enum vga_color bg)
{
    size_t x, y;
    terminal_setcolor(fg, bg);

    for (x = minX; x < maxX; ++x)
    {
        for (y = minY; y < maxY; ++y)
        {
            terminal_set_pos(x, y);
            terminal_writestring(" ");
        }
    }

}

void drawImage(enum vga_color img[25][80])
{
    size_t x, y;
    for (x = 0; x < 80; ++x)
    {
        for (y = 0; y < 25; ++y)
        {
            terminal_set_pos(x,y);
            terminal_setcolor(0, img[y][x]);
            terminal_writestring(" ");
        }
    }
}