#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_G = 26;
const int BTN_PIN_R = 28;
const int LED_PIN_G = 6;
const int LED_PIN_R = 4;

int main() {
  stdio_init_all();

  // Inicialização de pinos
  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  // Estados
  int LED_R_STATE = 0;
  int LED_G_STATE = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      LED_R_STATE = !LED_R_STATE;
      gpio_put(LED_PIN_R, LED_R_STATE);
      while (!gpio_get(BTN_PIN_R)) {
      };
    }

    if (!gpio_get(BTN_PIN_G)) {
      LED_G_STATE = !LED_G_STATE;
      gpio_put(LED_PIN_G, LED_G_STATE);
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
  }
}
