#include "stm32f10x.h"   // Device header
#include "Delay.h"  // Device:Startup


/*讓 LED 閃爍*/
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_Instruction;
	GPIO_Instruction.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Instruction.GPIO_Pin = GPIO_Pin_0;
	GPIO_Instruction.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_Instruction);
	
	
    while (1)
    {
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);
    }
}
