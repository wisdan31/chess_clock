#include <stdio.h>
#include <stdint.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <driver/gpio.h>

#include "esp_timer.h"
#include "button.h"

#define BUTTON_GPIO GPIO_NUM_18

static void button_task(void *arg)
{
    int stable_state = 0;

    int64_t ;

    while (1)
    {
        int candidate_state = gpio_get_level(BUTTON_GPIO);

        if (candidate_state == 1 && stable_state == 0)
        {
            printf("Button pressed!\n");
        }

        if (candidate_state == 0 && stable_state == 1)
        {
            printf("Button released!\n");
        }

        stable_state = candidate_state;

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
