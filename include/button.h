#ifndef BUTTON_H
#define BUTTON_H

#include <driver/gpio.h>

typedef enum {
    WHITE_PLAYER,
    BLACK_PLAYER
} button_id;

typedef struct {
  gpio_num_t gpio;
  button_id button;
} button_config;

void button_init(button_config config);

#endif