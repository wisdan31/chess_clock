
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <driver/gpio.h>

#include "button.h"

#define BUTTON_GPIO GPIO_NUM_18

static void button_task(void *arg)
{
    int previous_state = 0;

    while (1)
    {
        int current_state = gpio_get_level(BUTTON_GPIO);

        if (current_state == 1 && previous_state == 0)
        {
            printf("Button pressed!\n");
        }

        if (current_state == 0 && previous_state == 1)
        {
            printf("Button released!\n");
        }

        previous_state = current_state;

        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

void button_init(void)
{
    gpio_config_t button_config = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_down_en = GPIO_PULLDOWN_ENABLE};

    gpio_config(&button_config);

    xTaskCreate(
        button_task,
        "button_task",
        2048,
        NULL,
        5,
        NULL);
}
