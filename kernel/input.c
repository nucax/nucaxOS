#include "input.h"
#include "graphics.h"

static int mouseX=400, mouseY=300;

void init_keyboard() {}
void init_mouse() {}
void poll_input() {
    // placeholder: simulate moving cursor slowly
    mouseX = (mouseX+1) % SCREEN_W;
}

void draw_cursor() {
    draw_rect(mouseX, mouseY, 3, 3, 0xFFFFFF);
}
