#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__ 1

void drawBox(size_t minX, size_t minY, size_t  maxX, size_t maxY, enum vga_color fg, enum vga_color bg);
void drawImage(enum vga_color img[25][80]);

#endif