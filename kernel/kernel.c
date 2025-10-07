#include "graphics.h"
#include "input.h"
#include "task.h"
#include "fat32.h"

void kernel_main(void) {
    init_graphics();
    draw_background(0xC0C0C0);
    draw_rect(0, SCREEN_H-20, SCREEN_W, 20, 0x000080); // taskbar
    draw_text(4, SCREEN_H-18, "nucaxOS v0.1", 0xFFFFFF);

    init_keyboard();
    init_mouse();

    while (1) {
        poll_input();
        draw_cursor();
    }
}
