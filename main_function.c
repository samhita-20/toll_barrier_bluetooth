#include<lpc21xx.h>
#include"lcd_header.h"
#include"bluetooth_header.h"
#include"servo_motor.h"
#define led1 1<<10
void PROJECT_INIT(void);
char *toll;
char *open="open";
char *close="close";

void EXT_INT0_isr(void)__irq
{
	
LCD_STR("VEHICLE DETECTED");	
str_tx("VEHICLE DETECTED\n");
LCD_COMMAND(0X01);
LCD_COMMAND(0X80);
LCD_STR("TOLL: OPEN (or) CLOSE : ");
str_tx("TOLL: OPEN (or) CLOSE\n");
toll = str_rx();
LCD_COMMAND(0X01);
LCD_STR(toll);
delay_ms(1000);
if(strcmp(toll,open)==0)
{
IOCLR0 = led1;
PWM_90deg();
str_tx("TOLL OPEN\n");
LCD_COMMAND(0X01);
LCD_COMMAND(0X80);
LCD_STR("TOLL OPEN");	
}
if(strcmp(toll,close)==0)
{
IOSET0 = led1;
PWM_0deg();
str_tx("TOLL closed\n");
LCD_COMMAND(0X01);
LCD_COMMAND(0X80);
LCD_STR("TOLL closeD");		
}
EXTINT = 0X01;
VICVectAddr = 0;
}
int main()
{
int cnt = 0;
config_uart0();
LCD_INIT();
PROJECT_INIT();
PWM_INIT();
PINSEL1|=1<<0;//P0.16=EINT0 PIN
IODIR0|= led1;
IOSET0 = led1;
//All are IRQ
VICIntSelect = 0X00000000;
//slot0 for EINT0
VICVectCntl0 = (1<<5)|14;
VICVectAddr0 = (int)EXT_INT0_isr;
//falling edge triggered mode
EXTMODE = 0X01;
EXTPOLAR = 0X00;
//enabling external interrupt0 and external interuupt 1
VICIntEnable = (1<<14);
while(1)
{
cnt++;
}
}
void PROJECT_INIT(void)
{
char project_name[40]="TITLE : TOLL BARRIER USING BLEUTOOTH"; 	
LCD_COMMAND(0X80);
LCD_STR(project_name);
delay_ms(5000);
LCD_COMMAND(0X01);
LCD_COMMAND(0X80);	
}
