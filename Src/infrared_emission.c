//
// Created by Pandior on 2020/5/31.
//

#include "infrared_emission.h"


void send_data(uint8_t data) {
    uint8_t tx_bit = 0;
    for (int i = 0; i < 8; i++) {
        tx_bit = data & 0x01;
        if (tx_bit) {
            HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 1);
            delay_us(600);
            HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 0);
            delay_us(1685);
        } else {
            HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 1);
            delay_us(600);
            HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 0);
            delay_us(560);
        }
        data=data>>1;
    }
}

void txd(uint8_t addr, uint8_t dat) {
    HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 1);
    delay_us(9000);
    HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 0);
    delay_us(4500);
    send_data(addr);
    send_data(~addr);
    send_data(dat);
    send_data(~dat);
    HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 1);
    delay_us(800);
    HAL_GPIO_WritePin(TXD_GPIO_Port, TXD_Pin, 0);

}



