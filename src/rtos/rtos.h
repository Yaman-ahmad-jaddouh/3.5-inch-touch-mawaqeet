#include <Arduino.h>
#include <lvgl.h>
#include "../ui/ui.h"
#include "../ui_shortage/ui_shortage.h"

typedef struct
{
    char ssid[32];
    char password[64];
    /* data */
} WiFiSetting;

extern TaskHandle_t task_wifi_search;
extern TaskHandle_t task_wifi_connect;
extern WiFiSetting wifiUser;

void Task_init();