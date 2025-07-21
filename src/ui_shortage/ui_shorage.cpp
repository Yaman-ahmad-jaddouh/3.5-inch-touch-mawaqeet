#include "./ui_shortage.h"
lv_obj_t *ui_list = NULL;

const char *default_kb_map_lc_custom[] = {"1#", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
                                          "ABC", "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_NEW_LINE, "\n",
                                          "_", "-", "z", "x", "c", "v", "b", "n", "m", ".", ",", ":", "\n",
                                          LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, ""};
const char *default_kb_map_arabic[] = {"ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "\n",
                                       "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "مسح", "\n",
                                       "ذ", "ء", "ؤ", "ر", "ي", "ة", "و", "ى", "إ", "د", "ز", "ظ", "\n",
                                       "تغيير اللغة", "يسار", " ", "يمين", "موافق", ""};

typedef struct
{
    uint8_t a;
    uint8_t b;
} uu;
uu j = {.a = 10, .b = 20};
void get_id(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    const char *txt = lv_label_get_text(target);
    Serial.println(String(txt));
    uu *d = (uu *)lv_obj_get_user_data(target);
    Serial.println("test");
    if (d)
    {
        Serial.println(d->a);
        Serial.println(d->b);
    }
    else
    {
        Serial.println("aas");
    }
}

void ui_shortage_index_label_relay_name()
{
    lv_obj_t *ui_PanelRelayInfoArray[] = {ui_PanelRelayInfo1, ui_PanelRelayInfo2, ui_PanelRelayInfo3, ui_PanelRelayInfo4, ui_PanelRelayInfo5, ui_PanelRelayInfo6, ui_PanelRelayInfo7, ui_PanelRelayInfo8};
    lv_obj_t *ui_LabelInfoIndex;
    lv_obj_t *ui_Label_relayName = lv_label_create(ui_PanelRelaySetting);

    for (byte index = 1; index <= 8; index++)
    {
        ui_LabelInfoIndex = lv_label_create(ui_PanelRelayInfoArray[index - 1]);
        lv_obj_set_width(ui_LabelInfoIndex, LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_LabelInfoIndex, LV_SIZE_CONTENT); /// 1
        lv_obj_set_x(ui_LabelInfoIndex, 5);
        lv_obj_set_y(ui_LabelInfoIndex, 5);
        lv_label_set_text(ui_LabelInfoIndex, String(index).c_str());
        lv_obj_set_style_text_font(ui_LabelInfoIndex, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void ui_shortage_index_label_relay_control()
{
    lv_obj_t *ui_ContainerArray[] = {ui_Container3, ui_Container4, ui_Container5, ui_Container6, ui_Container7, ui_Container8, ui_Container9, ui_Container10};
    lv_obj_t *ui_LabelContrainerIndex;

    for (byte index = 1; index <= 8; index++)
    {
        ui_LabelContrainerIndex = lv_label_create(ui_ContainerArray[index-1]);
        lv_obj_set_width(ui_LabelContrainerIndex, LV_SIZE_CONTENT);  /// 1
        lv_obj_set_height(ui_LabelContrainerIndex, LV_SIZE_CONTENT); /// 1
        lv_obj_set_align(ui_LabelContrainerIndex, LV_ALIGN_TOP_MID);
        lv_label_set_text(ui_LabelContrainerIndex, "3");
        lv_obj_set_style_text_font(ui_LabelContrainerIndex, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}
void ui_shorage_init()
{
    ui_list = lv_list_create(ui_TabPage4);
    lv_obj_set_style_text_font(ui_list, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_list, 0, 50);
    lv_obj_set_size(ui_list, 442, 200);
    lv_obj_set_align(ui_list, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_bg_color(ui_list, lv_color_hex(0xff2c2c3c), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_list, 0, LV_PART_MAIN | LV_STATE_SCROLLED);
    lv_obj_set_style_pad_right(ui_list, 0, LV_PART_MAIN | LV_STATE_SCROLLED);
    lv_obj_set_style_pad_left(ui_list, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui_list, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_list, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_list, lv_color_hex(0xffffffff), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_list, lv_color_hex(0xff262635), LV_PART_SCROLLBAR | LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui_list, lv_color_hex(0xffffffff), LV_PART_SCROLLBAR | LV_STATE_FOCUSED);
    lv_obj_set_style_text_color(ui_list, lv_color_hex(0xffffffff), LV_PART_SCROLLBAR | LV_STATE_FOCUS_KEY);

    // contorl
    ui_shortage_index_label_relay_name();
    // ui_shortage_index_label_relay_control();
    ui_Label40 = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_Label40, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label40, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label40, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label40, "1");
    lv_obj_set_style_text_font(ui_Label40, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label42 = lv_label_create(ui_Container4);
    lv_obj_set_width(ui_Label42, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label42, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label42, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label42, "2");
    lv_obj_set_style_text_font(ui_Label42, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label44 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label44, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label44, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label44, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label44, "3");
    lv_obj_set_style_text_font(ui_Label44, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label46 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label46, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label46, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label46, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label46, "4");
    lv_obj_set_style_text_font(ui_Label46, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label48 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label48, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label48, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label48, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label48, "5");
    lv_obj_set_style_text_font(ui_Label48, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label50 = lv_label_create(ui_Container8);
    lv_obj_set_width(ui_Label50, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label50, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label50, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label50, "6");
    lv_obj_set_style_text_font(ui_Label50, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label52 = lv_label_create(ui_Container9);
    lv_obj_set_width(ui_Label52, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label52, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label52, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label52, "7");
    lv_obj_set_style_text_font(ui_Label52, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label54 = lv_label_create(ui_Container10);
    lv_obj_set_width(ui_Label54, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_Label54, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label54, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_Label54, "8");
    lv_obj_set_style_text_font(ui_Label54, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_table = lv_table_create(ui_programContentContainer);
    // lv_obj_center(ui_table);
    // lv_obj_set_scroll_dir(ui_table, LV_DIR_VER);

    // lv_obj_set_style_text_font(ui_table, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_align(ui_table, LV_ALIGN_TOP_LEFT);
    // lv_obj_set_pos(ui_table, 0, 70);
    // lv_obj_set_size(ui_table, 440, 250);

    // lv_obj_set_style_pad_left(ui_table, 0, LV_PART_MAIN | LV_STATE_SCROLLED);
    // lv_obj_set_style_pad_right(ui_table, 0, LV_PART_MAIN | LV_STATE_SCROLLED);
    // lv_obj_set_style_pad_left(ui_table, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    // lv_obj_set_style_pad_right(ui_table, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    // lv_obj_set_style_pad_top(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_row(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_column(ui_table, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    // lv_table_set_col_cnt(ui_table, 5);
    // lv_table_set_row_cnt(ui_table, 2);
    // // lv_table_set_row_cnt(ui_table, 4, 50);

    // lv_table_set_col_width(ui_table, 4, 50);
    // lv_table_set_col_width(ui_table, 3, 120);
    // lv_table_set_col_width(ui_table, 2, 70);
    // lv_table_set_col_width(ui_table, 1, 130);
    // lv_table_set_col_width(ui_table, 0, 70);

    // lv_table_set_cell_value(ui_table, 0, 4, "ID");
    // lv_table_set_cell_value(ui_table, 0, 3, "الاسم");
    // lv_table_set_cell_value(ui_table, 0, 2, "الوظيفة");
    // lv_table_set_cell_value(ui_table, 0, 1, "الأيام");
    // lv_table_set_cell_value(ui_table, 0, 0, "الوقت");

    // // lv_label_set_long_mode(ui_table, LV_LABEL_LONG_SCROLL);
    // // lv_obj_set_
    // for (byte i = 1; i < 8; i++)
    // {
    //     lv_table_set_cell_value(ui_table, i, 4, "99");
    //     lv_table_set_cell_value(ui_table, i, 3, " مكيف الجامع");
    //     lv_table_set_cell_value(ui_table, i, 2, "تشغيل");
    //     lv_table_set_cell_value(ui_table, i, 1, "sa su mo tu we th fr");
    //     lv_table_set_cell_value(ui_table, i, 0, "00:00");
    // }
    lv_obj_t *ui_Container12 = lv_obj_create(ui_ContainerProgram);
    lv_obj_remove_style_all(ui_Container12);
    lv_obj_set_width(ui_Container12, 440);
    lv_obj_set_height(ui_Container12, 30);
    lv_obj_clear_flag(ui_Container12, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    lv_obj_t *ui_Label45 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label45, 50);
    lv_obj_set_height(ui_Label45, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label45, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label45, "ID");
    lv_obj_set_style_text_align(ui_Label45, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label45, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_Label47 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label47, 120);
    lv_obj_set_height(ui_Label47, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label47, -50);
    lv_obj_set_y(ui_Label47, 0);
    lv_obj_set_align(ui_Label47, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label47, "الاسم");
    lv_obj_set_style_text_align(ui_Label47, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label47, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_Label49 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label49, 70);
    lv_obj_set_height(ui_Label49, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label49, -170);
    lv_obj_set_y(ui_Label49, 0);
    lv_obj_set_align(ui_Label49, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label49, "الوظيفة");
    lv_obj_set_style_text_align(ui_Label49, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label49, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_Label51 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label51, 130);
    lv_obj_set_height(ui_Label51, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label51, -240);
    lv_obj_set_y(ui_Label51, 0);
    lv_obj_set_align(ui_Label51, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label51, "الأيام");
    lv_obj_set_style_text_align(ui_Label51, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label51, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_Label53 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label53, 70);
    lv_obj_set_height(ui_Label53, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label53, -370);
    lv_obj_set_y(ui_Label53, 0);
    lv_obj_set_align(ui_Label53, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label53, "الوقت");
    lv_obj_set_style_text_align(ui_Label53, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label53, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container12 = lv_obj_create(ui_ContainerProgram);
    lv_obj_remove_style_all(ui_Container12);
    lv_obj_set_width(ui_Container12, 440);
    lv_obj_set_height(ui_Container12, 30);
    lv_obj_set_x(ui_Container12, 0);
    lv_obj_set_y(ui_Container12, 30);

    lv_obj_clear_flag(ui_Container12, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    lv_obj_t *ui_Label60 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label60, 50);
    lv_obj_set_height(ui_Label60, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label60, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label60, "99");

    lv_obj_add_flag(ui_Label60, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(ui_Label60, get_id, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_text_align(ui_Label60, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_font(ui_Label60, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label47 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label47, 120);
    lv_obj_set_height(ui_Label47, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label47, -50);
    lv_obj_set_y(ui_Label47, 0);
    lv_obj_set_align(ui_Label47, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label47, "مكيف");
    lv_obj_set_style_text_align(ui_Label47, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label47, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label49 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label49, 70);
    lv_obj_set_height(ui_Label49, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label49, -170);
    lv_obj_set_y(ui_Label49, 0);
    lv_obj_set_align(ui_Label49, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label49, "تشغيل");
    lv_obj_set_style_text_align(ui_Label49, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label49, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label51 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label51, 130);
    lv_obj_set_height(ui_Label51, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label51, -240);
    lv_obj_set_y(ui_Label51, 0);
    lv_obj_set_align(ui_Label51, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label51, "sa ss ss ss ss ss ss");
    lv_obj_set_style_text_align(ui_Label51, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label51, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label53 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label53, 70);
    lv_obj_set_height(ui_Label53, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label53, -370);
    lv_obj_set_y(ui_Label53, 0);
    lv_obj_set_align(ui_Label53, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label53, "00:00");
    lv_obj_set_style_text_align(ui_Label53, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label53, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container12 = lv_obj_create(ui_ContainerProgram);
    lv_obj_remove_style_all(ui_Container12);
    lv_obj_set_width(ui_Container12, 440);
    lv_obj_set_height(ui_Container12, 30);
    lv_obj_set_x(ui_Container12, 0);
    lv_obj_set_y(ui_Container12, 60);

    lv_obj_clear_flag(ui_Container12, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_Label45 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label45, 50);
    lv_obj_set_height(ui_Label45, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_Label45, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label45, "100");
    lv_obj_add_flag(ui_Label45, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_style()

    lv_obj_set_style_text_align(ui_Label45, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label45, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Label45, get_id, LV_EVENT_CLICKED, NULL);

    ui_Label47 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label47, 120);
    lv_obj_set_height(ui_Label47, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label47, -50);
    lv_obj_set_y(ui_Label47, 0);
    lv_obj_set_align(ui_Label47, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label47, "مكيف");
    lv_obj_set_style_text_align(ui_Label47, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label47, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label49 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label49, 70);
    lv_obj_set_height(ui_Label49, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label49, -170);
    lv_obj_set_y(ui_Label49, 0);
    lv_obj_set_align(ui_Label49, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label49, "تشغيل");
    lv_obj_set_style_text_align(ui_Label49, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label49, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label51 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label51, 130);
    lv_obj_set_height(ui_Label51, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label51, -240);
    lv_obj_set_y(ui_Label51, 0);
    lv_obj_set_align(ui_Label51, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label51, "sa ss ss ss ss ss ss");
    lv_obj_set_style_text_align(ui_Label51, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label51, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label53 = lv_label_create(ui_Container12);
    lv_obj_set_width(ui_Label53, 70);
    lv_obj_set_height(ui_Label53, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_Label53, -370);
    lv_obj_set_y(ui_Label53, 0);
    lv_obj_set_align(ui_Label53, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Label53, "00:00");
    lv_obj_set_style_text_align(ui_Label53, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label53, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_add_event_cb(ui_table, table_pressed_get_id, LV_EVENT_CLICKED, NULL);

    // lv_obj_add_flag(ui_Label55, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_flag(ui_Label56, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_flag(ui_Label57, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_flag(ui_Label58, LV_OBJ_FLAG_CLICKABLE);

    // lv_obj_set_user_data(ui_Label57, &j);
    // lv_obj_set_user_data(ui_Label58, &j);

    // lv_obj_add_event_cb(ui_Label55, get_id, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(ui_Label56, get_id, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(ui_Label57, get_id, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(ui_Label58, get_id, LV_EVENT_CLICKED, NULL);
    updateProgram();
}

void updateProgram()
{
    //     lv_obj_clean(ui_Container11);
    //     lv_obj_t *mainContainer = lv_obj_create(ui_Container11);
    //     lv_obj_create(ui_programContentContainer);
    //     lv_obj_remove_style_all(mainContainer);
    //     lv_obj_set_width(mainContainer, 440);
    //     lv_obj_set_height(mainContainer, 250);
    //     lv_obj_set_x(mainContainer, 0);
    //     lv_obj_set_y(mainContainer, 70);
    //     lv_obj_clear_flag(mainContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    //     lv_obj_t *ui_Container13 = lv_obj_create(ui_Container11);
    //     lv_obj_remove_style_all(ui_Container13);
    //     lv_obj_set_width(ui_Container13, 440);
    //     lv_obj_set_height(ui_Container13, 30);
    //     lv_obj_set_x(ui_Container13, 0);
    //     lv_obj_set_y(ui_Container13, 30);
    //     lv_obj_clear_flag(ui_Container13, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags

    //     lv_obj_t *ui_LabelID = lv_label_create(ui_Container13);
    //     lv_obj_set_width(ui_LabelID, 50);
    //     lv_obj_set_height(ui_LabelID, LV_SIZE_CONTENT); /// 1
    //     lv_obj_set_align(ui_LabelID, LV_ALIGN_RIGHT_MID);
    //     lv_label_set_text(ui_LabelID, "ID");
    //     lv_obj_set_style_text_align(ui_LabelID, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     lv_obj_set_style_text_font(ui_LabelID, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    //     lv_obj_t *ui_LabelName = lv_label_create(ui_Container13);
    //     lv_obj_set_width(ui_LabelName, 50);
    //     lv_obj_set_height(ui_LabelName, LV_SIZE_CONTENT); /// 1
    //     lv_obj_set_align(ui_LabelName, LV_ALIGN_RIGHT_MID);
    //     lv_obj_set_x(ui_Label51, -240);
    //     lv_obj_set_y(ui_Label51, 0);
    //     lv_label_set_text(ui_LabelName, "الأسم");
    //     lv_obj_set_style_text_align(ui_LabelName, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     lv_obj_set_style_text_font(ui_LabelName, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // lv_event_send(ui_Label55, LV_EVENT_VALUE_CHANGED, 99);
    // }

    // // ui_Label55 = lv_label_create(ui_Container13);
    // // lv_obj_set_width(ui_Label55, 50);
    // // lv_obj_set_height(ui_Label55, LV_SIZE_CONTENT); /// 1
    // // lv_obj_set_align(ui_Label55, LV_ALIGN_RIGHT_MID);
    // // lv_label_set_text(ui_Label55, "99");
    // // lv_obj_set_style_text_align(ui_Label55, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_text_font(ui_Label55, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // // lv_event_send(ui_Label55, LV_EVENT_VALUE_CHANGED, 99);

    // // ui_Label56 = lv_label_create(ui_Container13);
    // // lv_obj_set_width(ui_Label56, 120);
    // // lv_obj_set_height(ui_Label56, LV_SIZE_CONTENT); /// 1
    // // lv_obj_set_x(ui_Label56, -50);
    // // lv_obj_set_y(ui_Label56, 0);
    // // lv_obj_set_align(ui_Label56, LV_ALIGN_RIGHT_MID);
    // // lv_label_set_text(ui_Label56, "تشغيل مكيف");
    // // lv_obj_set_style_text_align(ui_Label56, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_text_font(ui_Label56, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // // ui_Label57 = lv_label_create(ui_Container13);
    // // lv_obj_set_width(ui_Label57, 70);
    // // lv_obj_set_height(ui_Label57, LV_SIZE_CONTENT); /// 1
    // // lv_obj_set_x(ui_Label57, -170);
    // // lv_obj_set_y(ui_Label57, 0);
    // // lv_obj_set_align(ui_Label57, LV_ALIGN_RIGHT_MID);
    // // lv_label_set_text(ui_Label57, "تشغيل");
    // // lv_obj_set_style_text_align(ui_Label57, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_text_font(ui_Label57, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // // ui_Label58 = lv_label_create(ui_Container13);
    // // lv_obj_set_width(ui_Label58, 130);
    // // lv_obj_set_height(ui_Label58, LV_SIZE_CONTENT); /// 1
    // // lv_obj_set_x(ui_Label58, -240);
    // // lv_obj_set_y(ui_Label58, 0);
    // // lv_obj_set_align(ui_Label58, LV_ALIGN_RIGHT_MID);
    // // lv_label_set_text(ui_Label58, "sa su mo tu we th fr");
    // // lv_obj_set_style_text_align(ui_Label58, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_text_font(ui_Label58, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // // ui_Label59 = lv_label_create(ui_Container13);
    // // lv_obj_set_width(ui_Label59, 70);
    // // lv_obj_set_height(ui_Label59, LV_SIZE_CONTENT); /// 1
    // // lv_obj_set_x(ui_Label59, -370);
    // // lv_obj_set_y(ui_Label59, 0);
    // // lv_obj_set_align(ui_Label59, LV_ALIGN_RIGHT_MID);
    // // lv_label_set_text(ui_Label59, "00:00");
    // // lv_obj_set_style_text_align(ui_Label59, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_text_font(ui_Label59, &ui_font_NotoSans10, LV_PART_MAIN | LV_STATE_DEFAULT);
}