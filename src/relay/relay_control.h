#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H

#include <Arduino.h>

#define NUM_RELAYS 4

void init_relays();
void set_relay_state(uint8_t relay_num, bool state);
bool get_relay_state(uint8_t relay_num);
void toggle_relay(uint8_t relay_num);
void update_relay_gui();

#endif