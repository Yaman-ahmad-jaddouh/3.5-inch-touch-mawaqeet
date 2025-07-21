#include "eep.h"

uint16_t eep_touch_calData[5];
WiFi_Setting eep_wifi_setting;
Relay_Setting eep_relay_setting[8];

void init_eeprom()
{
    for (uint8_t i = 0; i < 8; i++)
    {
        strcpy(eep_relay_setting[i].name,"بدون اسم");
    }
    EEPROM.begin(EEPROM_TOTAL_SIZE + 10);
    if (EEPROM.read(0) != 1)
    {
        EEPROM.write(0, 1);
        EEPROM.put(START_WIFI_CER_ADDRESS, eep_wifi_setting);
        EEPROM.put(START_TOUCH_SCREEN_ADDRESS, eep_touch_calData);
        EEPROM.put(START_RELAY_SETTING_ADDRESS, eep_relay_setting);
        EEPROM.commit();
    }
    EEPROM.get(START_WIFI_CER_ADDRESS, eep_wifi_setting);
    EEPROM.get(START_TOUCH_SCREEN_ADDRESS, eep_touch_calData);
    EEPROM.get(START_RELAY_SETTING_ADDRESS, eep_relay_setting);
}
