#include "stm32f10x.h"
#include "led.h"

void delay(__IO uint32_t uiCount){
    for(; uiCount != 0; uiCount--);
}

void main(){
    LED_Init();
    uint16_t x = GPIO_Pin_0;
    
    while(1){
        GPIO_SetBits(GPIOB, GPIO_Pin_All);
        GPIO_ResetBits(GPIOB, x);
        x <<= 1;
        delay(50);
        
        if(x == 0){
            x = GPIO_Pin_0;
        }
    }
}