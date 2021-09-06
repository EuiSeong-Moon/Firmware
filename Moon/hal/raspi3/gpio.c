#include "gpio.h"
#include "mmio.h"

void gpio_init() {
    gpio_clear();
}

void gpio_set() {

}

void gpio_get() {

}

void gpio_clear() {
    mmio_write(GPCLR0,0x0FFFFFFFF);
    //31~22 bits reserved
    mmio_write(GPCLR1,0x3FFFFF);
}