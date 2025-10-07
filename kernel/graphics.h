#pragma once
#include <stdint.h>

extern int SCREEN_W, SCREEN_H;

void init_graphics();
void draw_pixel(int x,int y,uint32_t color);
void draw_rect(int x,int y,int w,int h,uint32_t color);
void draw_background(uint32_t color);
void draw_char(int x,int y,char c,uint32_t color);
void draw_text(int x,int y,const char*s,uint32_t color);
