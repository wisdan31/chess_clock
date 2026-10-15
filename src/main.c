#include <stdio.h>

#include <driver/gpio.h>

#include "button.h"

#define WHITE_PLAYER_BUTTON_GPIO GPIO_NUM_18
#define BLACK_PLAYER_BUTTON_GPIO GPIO_NUM_19

void app_main(void)
{
    printf("Starting ESP32...\n");

    button_init(WHITE_PLAYER_BUTTON_GPIO);
    button_init(BLACK_PLAYER_BUTTON_GPIO);
}
