#include "smg.h"
#include "spi.h"

void smg_display(int temp) {
    uint8_t display_num,zero =0;

    //显示第一位数字
    display_num = temp / 100;


    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, &smg_data[display_num], 1, 100);
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);



    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);



    //显示第二位数字
    display_num = smg_data[temp % 100 / 10] | 0x80;          //带上小数点


    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, &display_num, 1, 100);
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);


    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);



    //显示第三位数字
    display_num=temp%100%10;

    HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1,&smg_data[display_num],1,100);
    HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);


}