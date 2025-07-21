#include "./rtc_handler.h"
RTC_DS3231 rtc_clock;
DateTime currentTime;
char dayOfWeekArabic[7][18] = {"الأحد", "الاثنين", "الثلاثاء", "الأربعاء", "الخميس", "الجمعة", "السبت"};
char monthArabic[12][24] = {"كانون الثاني", "شباط", "آذار", "نيسان", "آيار", "حزيران", "تموز", "آب", "أيلول", "تشرين الأول", "تشرين الثاني", "كانون الأول"};

bool init_rtc()
{
    Wire.begin(32, 33);
    if (rtc_clock.begin())
    {
        currentTime = rtc_clock.now();
        return 1;
    }

    return 0;
}
bool rtc_update()
{

    if (!rtc_clock.lostPower())
    {
        currentTime = rtc_clock.now();
        return 1;
    }
    return 0;

    return 0;
}
void rtc_adjust(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second)
{
    DateTime settingTime = DateTime(year, month, day, hour, minute, second);
    rtc_clock.adjust(settingTime);
}
