#include <Arduino.h>
#include <lvgl.h>
#include "../ui/ui.h"
extern lv_obj_t *ui_list;
extern lv_obj_t *ui_table;

extern const char *default_kb_map_arabic[];
extern const char *default_kb_map_lc_custom[];

void ui_shorage_init();
void updateProgram();