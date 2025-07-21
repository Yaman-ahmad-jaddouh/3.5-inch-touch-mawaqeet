SET(SOURCES ui_comp_maincontentcontainer.c
    ui_comp.c
    ui_Screen1.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_img_mosuqe_png.c
    ui_img_nowifi_png.c
    ui_img_wifi_png.c
    ui_img_650607941.c
    ui_img_1867271658.c
    ui_img_help_png.c
    ui_img_1308353594.c
    fonts/ui_font_NotoSans10.c
    fonts/ui_font_NotoSans12.c
    fonts/ui_font_NotoSans14.c
    fonts/ui_font_NotoSans18.c
    fonts/ui_font_NotoSans20.c
    fonts/ui_font_NotoSans24.c)

add_library(ui ${SOURCES})
