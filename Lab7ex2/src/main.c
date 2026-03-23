#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2
#define BUTTON_PIN GPIO_NUM_19

void app_main(void)
{
    // -------- OUTPUT (LED) --------
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // -------- INPUT (BUTTON) --------
    gpio_reset_pin(BUTTON_PIN);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_pullup_en(BUTTON_PIN);  // as shown in your table

    while (1)
    {
        // Read button state
        int state = gpio_get_level(BUTTON_PIN);

        if (state == 0)
        {
            // Button pressed (because pull-up → pressed = 0)
            gpio_set_level(LED_PIN, 1);
        }
        else
        {
            // Button not pressed
            gpio_set_level(LED_PIN, 0);
        }
    }
}