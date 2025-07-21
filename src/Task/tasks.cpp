#include "tasks.h"
#include <lvgl.h>
#include "../Relay/relay_control.h"
// #include "schedule_manager.h"
#include "../wifi/wifi_handler.h"
#include "../lvgl/lvgl_ui.h"
#include "../eeprom/eep.h"
#include "../rtc/rtc_handler.h"
TaskHandle_t xLvglTaskHandle;
TaskHandle_t xRelayControlTaskHandle;
TaskHandle_t xScheduleTaskHandle;
TaskHandle_t xWifiTaskHandle;
TaskHandle_t xWifiConnectionTaskHandle;
TaskHandle_t xClockUpdateTaskHandle;

bool touchCalbration = 0;

void create_tasks()
{
    xTaskCreatePinnedToCore(
        lvgl_task,            // Task function
        "LVGL Task",          // Task name
        LVGL_TASK_STACK_SIZE, // Stack size
        NULL,                 // Parameters
        LVGL_TASK_PRIORITY,   // Priority
        &xLvglTaskHandle,     // Task handle
        1                     // Core (0 or 1)
    );
    xTaskCreatePinnedToCore(
        wifi_check_connection_task,          // Task function
        "WiFi Connection Task",              // Task name
        WIFI_CHECK_CONNECTION_SIZE,          // Stack size
        NULL,                                // Parameters
        WIFI_CHECK_CONNECTION_TASK_PRIORITY, // Priority
        &xClockUpdateTaskHandle,             // Task handle
        1                                    // Core (0 or 1)
    );

    xTaskCreatePinnedToCore(
        rtc_clock_update_task,      // Task function
        "RTC UPDATE Task",          // Task name
        CLOCK_UPDATE_SIZE,          // Stack size
        NULL,                       // Parameters
        CLOCK_UPDATE_PRIORITY,      // Priority
        &xWifiConnectionTaskHandle, // Task handle
        1                           // Core (0 or 1)
    );
}

void lvgl_task(void *pvParameters)
{
    for (;;)
    {
        if (digitalRead(0) == 0)
        {
            touchCalbration = 1;

            if (touchCalbration)
            {
                tft.fillScreen(TFT_BLACK);
            }
            else
            {
                init_lvgl();
            }
            vTaskDelay(pdMS_TO_TICKS(500));
            
        }
        if (touchCalbration)
        {
            tft.calibrateTouch(eep_touch_calData, TFT_MAGENTA, TFT_BLACK, 15);
            for (uint8_t i = 0; i < 5; i++)
            {
                Serial.println(eep_touch_calData[i]);
            }

            tft.setTouch(eep_touch_calData);

            EEPROM.put(START_TOUCH_SCREEN_ADDRESS, eep_touch_calData);
            EEPROM.commit();
            vTaskDelay(pdMS_TO_TICKS(1000));
            touchCalbration = 0;
            init_lvgl();
        }
        else
        {
            lv_task_handler();
            // Serial.println(ESP.getHeapSize());
        }
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void wifi_check_connection_task(void *pvParameters)
{
    for (;;)
    {
        check_wifi_connection();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void rtc_clock_update_task(void *pvParameters)
{
    for (;;)
    {
        if (rtc_update())
        {
            char clocktext[6];
            String DateDate = "";
            sprintf(clocktext, "%02d:%02d", currentTime.hour(), currentTime.minute());
            lv_label_set_text(ui_labelClock, clocktext);
            DateDate += String(currentTime.year()) + "  " + String(dayOfWeekArabic[currentTime.dayOfTheWeek()]) + " , "  + String(currentTime.day()) + " , " + String(monthArabic[currentTime.month() - 1]) + "   "  ;
            //   lv_label_set_text(ui_labelDayofWeek, dayOfWeekArabic[currentTime.dayOfTheWeek()]);
            lv_label_set_text(ui_Label43, DateDate.c_str());
        }
        else
        {
            lv_label_set_text(ui_labelClock, "--:--");
            lv_label_set_text(ui_Label43, "انقطع الاتصال");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));

        /* code */
    }
}