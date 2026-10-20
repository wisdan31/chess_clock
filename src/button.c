#include <stdio.h>
#include <stdint.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <driver/gpio.h>

#include "esp_timer.h"
#include "button.h"

static void button_task(void *arg)
{
    button_config config = *config;

    int stable_state = 0;
    int candidate_state = 0;

    int64_t candidate_since = esp_timer_get_time();

    while (1)
    {
        int button_level = gpio_get_level(config->gpio);
        int64_t timestamp = esp_timer_get_time();

        if (button_level != candidate_state)
        {
            candidate_state = button_level;
            candidate_since = timestamp;
        }

        if ((stable_state != candidate_state) && (timestamp - candidate_since >= 20000))
        {
            stable_state = candidate_state;

            if (stable_state == 1)
            {
                printf("Button pressed!\n");
            }
            else
            {
                printf("Button released!\n");
            }
        }

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void button_init(button_config config)
{
    gpio_config_t button_config = {
        .pin_bit_mask = (1ULL << config.gpio),
        .mode = GPIO_MODE_INPUT,
        .pull_down_en = GPIO_PULLDOWN_ENABLE};

    gpio_config(&button_config);

    xTaskCreate(
        button_task,
        "button_task",
        2048,
        &config,
        5,
        NULL);
}
