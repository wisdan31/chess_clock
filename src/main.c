#include <stdio.h>

#include <driver/gpio.h>

#include "button.h"

#define WHITE_PLAYER_BUTTON_GPIO GPIO_NUM_18

void app_main(void)
{
    printf("Starting ESP32...\n");

    button_init(WHITE_PLAYER_BUTTON_GPIO);
}
