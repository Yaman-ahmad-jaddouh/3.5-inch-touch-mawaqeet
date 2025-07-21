#include "./rtos.h"
#include <WiFi.h>

TaskHandle_t task_wifi_search;
TaskHandle_t task_wifi_connect;

WiFiSetting wifiUser;
void search_Wifi(void *par)
{
    // uint8_t numWiFi;

    // for (;;)
    // {
    //     numWiFi = WiFi.scanNetworks();
    //     if (numWiFi)
    //     {
    //         for (byte i = 0; i < numWiFi; i++)
    //         {
    //             String wifi = WiFi.SSID(i);
    //             lv_obj_t *btn = lv_list_add_btn(ui_list, LV_SYMBOL_WIFI, wifi.c_str());
    //             lv_obj_add_event_cb(btn, handle_wifi_selected, LV_EVENT_CLICKED, NULL);
    //         }
    //         lv_label_set_text(ui_Label30, "تم الانتهاء من البحث");
    //         vTaskDelay(1000 / portTICK_PERIOD_MS);
    //         lv_label_set_text(ui_Label30, "");
    //     }
    //     else
    //     {
    //         lv_label_set_text(ui_Label30, "لا يوجد شبكات");
    //         vTaskDelay(1000 / portTICK_PERIOD_MS);
    //         lv_label_set_text(ui_Label30, "");
    //     }
    //     vTaskSuspend(task_wifi_search);
    // }
}
void connect_Wifi(void *par)
{
    for (;;)
    {
        if (WiFi.status() != WL_CONNECTED)
        {
            // lv_image_set_src(objects.image_wifi_off_ss, &img_img_wifi_on);
            //

            lv_obj_clear_flag(ui_imageNoWiFi, LV_OBJ_FLAG_HIDDEN);
            // lv_obj_add_flag(ui_imagWiFi, LV_OBJ_FLAG_HIDDEN);

            // ui_imageWiFiState.
        }
        else
        {
            // lv_obj_clear_flag(ui_imagWiFi, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_imageNoWiFi, LV_OBJ_FLAG_HIDDEN);
        }
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}
void Task_init()
{

    xTaskCreate(search_Wifi, "task_wifi_search", 3072, NULL, 1, &task_wifi_search);
    xTaskCreate(connect_Wifi, "task_wifi_connect", 1024, NULL, 1, &task_wifi_connect);
    vTaskSuspend(task_wifi_search);
    vTaskSuspend(task_wifi_connect);
}