#include <Arduino.h>
#include <RTClib.h>

extern char dayOfWeekArabic[7][18];
extern char monthArabic[12][24];
extern DateTime currentTime;

bool init_rtc();
bool rtc_update();
void rtc_adjust(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);