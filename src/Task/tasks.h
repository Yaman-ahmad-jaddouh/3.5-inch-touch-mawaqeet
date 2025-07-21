#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
extern TaskHandle_t xLvglTaskHandle;
extern TaskHandle_t xRelayControlTaskHandle;
extern TaskHandle_t xScheduleTaskHandle;
extern TaskHandle_t xWifiTaskHandle;
extern TaskHandle_t xWifiConnectionTaskHandle;
extern TaskHandle_t xClockUpdateTaskHandle;



#define LVGL_TASK_PRIORITY 2
#define RELAY_TASK_PRIORITY 3
#define SCHEDULE_TASK_PRIORITY 2
#define WIFI_TASK_PRIORITY 1
#define WIFI_CHECK_CONNECTION_TASK_PRIORITY 1
#define CLOCK_UPDATE_PRIORITY 1



#define LVGL_TASK_STACK_SIZE 10240
#define RELAY_TASK_STACK_SIZE 2048
#define SCHEDULE_TASK_STACK_SIZE 2048
#define WIFI_TASK_STACK_SIZE 2048
#define WIFI_CHECK_CONNECTION_SIZE 3072
#define CLOCK_UPDATE_SIZE 2048





void create_tasks();
void lvgl_task(void *pvParameters);
void relay_control_task(void *pvParameters);
void schedule_task(void *pvParameters);
void wifi_task(void *pvParameters);
void wifi_check_connection_task(void *pvParameters);
void rtc_clock_update_task(void *pvParameters);
#endif
