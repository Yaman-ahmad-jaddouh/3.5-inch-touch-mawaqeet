#ifndef EEP_H
#define EEP_H
#include <Arduino.h>
#include <EEPROM.h>

#define WiFi_CER_SIZE 32 + 64 // size in byte : ssid 32: password :64
#define TOUCH_SCREEN_CALBRATION_SIZE 10
#define RELAY_SETTING_SIZE 368

#define EEPROM_TOTAL_SIZE WiFi_CER_SIZE + TOUCH_SCREEN_CALBRATION_SIZE + RELAY_SETTING_SIZE

#define START_WIFI_CER_ADDRESS 1
#define START_TOUCH_SCREEN_ADDRESS (START_WIFI_CER_ADDRESS + WiFi_CER_SIZE)
#define START_RELAY_SETTING_ADDRESS (START_TOUCH_SCREEN_ADDRESS + TOUCH_SCREEN_CALBRATION_SIZE)


typedef struct
{
    char ssid[32];
    char password[64];
} WiFi_Setting;

typedef struct
{
    char name[45];
    bool controlState = 0; // auto
} Relay_Setting;
extern uint16_t eep_touch_calData[5];
extern WiFi_Setting eep_wifi_setting;
extern Relay_Setting eep_relay_setting[8];

void init_eeprom();

#endif