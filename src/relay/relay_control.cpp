#include "relay_control.h"
#include <lvgl.h>
#include "ui/ui.h"
#include "ui_shortage/ui_shortage.h"
#include "eeprom/eep.h"

void update_relay_gui()
{
    lv_obj_t *lables[] = {ui_LabelRelayNameSetting1, ui_LabelRelayNameSetting2, ui_LabelRelayNameSetting3, ui_LabelRelayNameSetting4, ui_LabelRelayNameSetting5, ui_LabelRelayNameSetting6, ui_LabelRelayNameSetting7, ui_LabelRelayNameSetting8};
    lv_obj_t *switchs[] = {ui_SwitchAutoRelay1, ui_SwitchAutoRelay2, ui_SwitchAutoRelay3, ui_SwitchAutoRelay4, ui_SwitchAutoRelay5, ui_SwitchAutoRelay6, ui_SwitchAutoRelay7, ui_SwitchAutoRelay8};
    lv_obj_t *lablesControl[] = {ui_LabelControlState1, ui_LabelControlState2, ui_LabelControlState3, ui_LabelControlState4, ui_LabelControlState5, ui_LabelControlState6, ui_LabelControlState7, ui_LabelControlState8};

    for (uint8_t i = 0; i < 8; i++)
    {
        if (strlen(eep_relay_setting[i].name) > 0)
        {
            lv_label_set_text(lables[i], eep_relay_setting[i].name);
        }
        if (eep_relay_setting[i].controlState)
        {
            lv_label_set_text(lablesControl[i], "يدوي");
            lv_obj_add_state(switchs[i], LV_STATE_CHECKED);
        }
        else
        {
            lv_label_set_text(lablesControl[i], "تلقائي");
            lv_obj_clear_state(switchs[i], LV_STATE_CHECKED);
        }
    }
}