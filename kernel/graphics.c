#include "graphics.h"
#include <stdint.h>

uint32_t *vram = (uint32_t*)0xE0000000; // typical linear framebuffer addr
int pitch = 1024;
int SCREEN_W = 800;
int SCREEN_H = 600;

void init_graphics() {
    // On real hardware you'd query VBE mode from bootloader (TODO)
}

void draw_pixel(int x, int y, uint32_t color) {
    if (x<0 || y<0 || x>=SCREEN_W || y>=SCREEN_H) return;
    vram[y*pitch + x] = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int j=0;j<h;j++)
        for (int i=0;i<w;i++)
            draw_pixel(x+i,y+j,color);
}

void draw_background(uint32_t color) {
    draw_rect(0,0,SCREEN_W,SCREEN_H,color);
}

// basic 8x8 font that is a placeholder for now :3
static unsigned char font8x8_basic[128][8] = {
    ['A'] = {0x18,0x24,0x42,0x7E,0x42,0x42,0x42,0},
    ['O'] = {0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0},
};

void draw_char(int x,int y,char c,uint32_t color){
    for (int cy=0;cy<8;cy++)
        for (int cx=0;cx<8;cx++)
            if (font8x8_basic[(int)c][cy] & (1<<(7-cx)))
                draw_pixel(x+cx,y+cy,color);
}

void draw_text(int x,int y,const char* s,uint32_t color){
    for (;*s;s++,x+=8)
        draw_char(x,y,*s,color);
}
