#include <Arduino.h>
#include "Task/tasks.h"
#include "lvgl/lvgl_ui.h"
#include "rtc/rtc_handler.h"
#include "eeprom/eep.h"
#include "relay/relay_control.h"
// month
// extern DateTime currentTime;

/* TFT instance */

uint32_t timer12;

void setup()
{
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  init_eeprom();
  init_lvgl();
  init_rtc();
  create_tasks();
  update_relay_gui();
}
void loop()
{
  vTaskDelete(NULL);
  // let the GUI do its work
  // lv_timer_handler();

  // if (rtc_update())
  // {
  //   char clocktext[6];
  //   sprintf(clocktext, "%02d:%02d", currentTime.hour(), currentTime.minute());
  //   lv_label_set_text(ui_labelClock, clocktext);
  //   lv_label_set_text(ui_lableYear, String(currentTime.year()).c_str());
  //   lv_label_set_text(ui_lableMonth, monthArabic[currentTime.month() - 1]);
  //   lv_label_set_text(ui_labelDayofMonth, String(currentTime.day()).c_str());
  //   lv_label_set_text(ui_labelDayofWeek, dayOfWeekArabic[currentTime.dayOfTheWeek()]);
  // }

  // else
  // {
  //   lv_label_set_text(ui_labelClock, "--:--");
  //   lv_label_set_text(ui_lableYear, "");
  //   lv_label_set_text(ui_lableMonth, "انقطع الاتصال");
  //   lv_label_set_text(ui_labelDayofMonth, "");
  //   lv_label_set_text(ui_labelDayofWeek, "");
  // }
  // put your main code here, to run repeatedly:
}
