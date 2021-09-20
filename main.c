// Servo Motor Control

#include "stm32f4xx.h"
#define ARM_MATH_CM4

void GPIO_Init(void);
void TIM2_Init(void);
void TIM4_ms_Delay(uint32_t delay);

void GPIO_Init(){
	RCC->AHB1ENR |= 1; //Enable GPIOA clock
	GPIOA->AFR[0] |= 0x00100000; // Select the PA5 pin in alternate function mode
	GPIOA->MODER |= 0x00000800; //Set the PA5 pin alternate function
}

void TIM2_Init(){
	RCC->APB1ENR |=1;
	TIM2->PSC = 16-1; //Setting the clock frequency to 1MHz.
	TIM2->ARR = 20000; // Total period of the timer
	TIM2->CNT = 0;
	TIM2->CCMR1 = 0x0060; //PWM mode for the timer
	TIM2->CCER |= 1; //Enable channel 1 as output
	TIM2->CCR1 = 500; // Pulse width for PWM
}

void TIM4_ms_Delay(uint32_t delay){
	RCC->APB1ENR |= 1<<2; //Start the clock for the timer peripheral
	TIM4->PSC = 16000-1; //Setting the clock frequency to 1kHz.
	TIM4->ARR = (delay); // Total period of the timer
	TIM4->CNT = 0;
	TIM4->CR1 |= 1; //Start the Timer
	while(!(TIM4->SR & TIM_SR_UIF)){} //Polling the update interrupt flag
	TIM4->SR &= ~(0x0001); //Reset the update interrupt flag
}

int main(){
	RCC->CFGR |= 0<<10; // set APB1 = 16 MHz
	GPIO_Init();
	TIM2_Init();
	TIM2->CR1 |= 1;
	while(1){

		if(TIM2->CCR1 < 2500){
			TIM2->CCR1 = TIM2->CCR1 + 50;
			TIM4_ms_Delay(50);
		}
		else{
			TIM2->CCR1 = 500;
			TIM4_ms_Delay(50);
		}
	}
}

