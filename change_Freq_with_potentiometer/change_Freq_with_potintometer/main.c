/*
 * change_Freq_with_potintometer.c
 *
 * Created: 7/10/2023 5:59:06 PM
 * Author : abdelrhman mattar
 */ 

#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "lcd.h"
#include "ADC.h"
#include "timer_0.h"
volatile unsigned short x;
int main(void)
{
	DDRB=0XFF;
	ADC_vinit(0);
	lcd_init();
	Timer0_Vinit(CTC_Mode , PRESCALAR_8 , Togle , 0);
	char arr[4],brr[5];
	
    /* Replace with your application code */
    while (1) 
    {
		movecurse(1,1);
		x=ADC_u16Read();
		OCR0=x/4;
		PORTC = OCR0;
		sprintf(arr,"%d",OCR0);
		sprintf(brr,"%d",x);
		lcd_string(arr);
		_delay_ms(300);
		movecurse(2,1);
		_delay_ms(5);
		lcd_string(brr);
		_delay_ms(300);
    }
}

