
#include "stm32f3xx.h"

int main() {

    GPIO_SetPortMode(GPIOA_ADDR, 0, GPIO_MODE_ANALOG);
    GPIO_SetPortMode(GPIOA_ADDR, 1, GPIO_MODE_ALTERNATE);
    GPIO_SetPortMode(GPIOA_ADDR, 2, GPIO_MODE_OUTPUT);
    GPIO_SetPortMode(GPIOA_ADDR, 3, GPIO_MODE_ALTERNATE);

    return 0;
}
