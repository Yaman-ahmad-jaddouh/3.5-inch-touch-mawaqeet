#ifndef LVGL_UI_H
#define LVGL_UI_H
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "../ui/ui.h"
#include "../ui_shortage/ui_shortage.h"
extern TFT_eSPI tft;
extern  const char *default_kb_map_arabic[];
void init_lvgl();
// void lvgl_update_ui();
// void create_main_screen();
// void update_relay_status_ui();

#endif