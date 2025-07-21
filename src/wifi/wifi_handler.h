#ifndef WIFI_HANDLER_H
#define WIFI_HANDLER_H
#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>
#include "../ui/ui.h"
#include "../ui_shortage/ui_shortage.h"
#include "../eeprom/eep.h"

#define  WIFI_IS_CONNECTED 0
#define  WIFI_IS_DISCONNECTED 1

extern bool wifi_state;

void init_wifi();
void scan_wifi_networks();
void check_wifi_connection();

#endif