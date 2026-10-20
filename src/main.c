#include <stdio.h>

#include <driver/gpio.h>

#include "button.h"

#define WHITE_PLAYER_BUTTON_GPIO GPIO_NUM_18
#define BLACK_PLAYER_BUTTON_GPIO GPIO_NUM_19



void app_main(void)
{
    printf("Starting clock...\n");

    button_config white_button = {
        .gpio = WHITE_PLAYER_BUTTON_GPIO,
        .button = WHITE_PLAYER
    };

    button_config black_button = {
        .gpio = BLACK_PLAYER_BUTTON_GPIO,
        .button = BLACK_PLAYER
    };

    button_init(white_button);
    button_init(black_button);

    printf("Clock is ready to use.");
}
