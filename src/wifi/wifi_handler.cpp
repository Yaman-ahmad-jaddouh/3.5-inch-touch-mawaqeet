#include "wifi_handler.h"

bool wifi_state = 0;
void init_wifi()
{
    WiFi.mode(WIFI_STA);
}

void scan_wifi_networks()
{

    int16_t numNetwork = WiFi.scanNetworks();
    vTaskDelay(10 / portTICK_PERIOD_MS);
    Serial.println(numNetwork);
    if (numNetwork > 0)
    {
        if (ui_list != NULL)
            lv_obj_clean(ui_list);

        vTaskDelay(50 / portTICK_PERIOD_MS);

        for (uint16_t i = 0; i < numNetwork; i++)
        {
            String wifi = WiFi.SSID(i);
            Serial.println(wifi);
            lv_obj_add_event_cb(lv_list_add_btn(ui_list, LV_SYMBOL_WIFI, wifi.c_str()), handle_wifi_selected, LV_EVENT_CLICKED, NULL);
            Serial.println("passed");
            vTaskDelay(pdMS_TO_TICKS(5));
        }
        lv_label_set_text(ui_Label30, "تم الانتهاء من البحث");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        lv_label_set_text(ui_Label30, "");
        lv_obj_clear_state(ui_Button6, LV_STATE_DISABLED);
    }
    else
    {
        lv_label_set_text(ui_Label30, "تم الانتهاء من البحث");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        lv_label_set_text(ui_Label30, "");
        lv_obj_clear_state(ui_Button6, LV_STATE_DISABLED);
    }
}

void check_wifi_connection()
{
    static uint32_t try_connect;
    wifi_state = WiFi.status() != WL_CONNECTED;
    if (millis() - try_connect > 10000)
    {

        if (wifi_state == WIFI_IS_DISCONNECTED)
        {
            if (strlen(eep_wifi_setting.ssid) > 0)
            {
                WiFi.begin(eep_wifi_setting.ssid, eep_wifi_setting.password);
            }
        }
        try_connect = millis();
    }
    if (wifi_state == WIFI_IS_DISCONNECTED)
    {
        lv_obj_clear_flag(ui_imageNoWiFi, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_imageWiFi, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_imageWiFi, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_imageNoWiFi, LV_OBJ_FLAG_HIDDEN);
    }
}