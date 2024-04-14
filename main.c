#include <LPC21xx.H>
#include"header.h"
//void led_shifting(void);

#define LED1 (1<<17) //p0.17
#define LED2 (1<<18) //p0.18
#define LED3 (1<<19) //p0.19
#define LED  (1<<17)

int main()
{
	unsigned char temp;
	
	uart0_init(9600);
	uart0_tx_string("Xarvis\r\n");
	IODIR0|=7<<17;
	IOSET0=7<<17;
	while(1)
	{
	uart0_tx_string("\r\n MENU");
	uart0_tx_string("\r\n a.LED1 ON" );
	uart0_tx_string("\r\n b.LED1 OFF");
	uart0_tx_string("\r\n c.LED2 ON");
	uart0_tx_string("\r\n d.LED2 OFF");
	uart0_tx_string("\r\n e.LED3 ON");
	uart0_tx_string("\r\n f.LED3 OFF");
	uart0_tx_string("\r\n g. All LED ON");
	uart0_tx_string("\r\n h. All LED OFF");
	uart0_tx_string("\r\n Chosse Option... XD- ");

	temp=uart0_rx(); //waiting for command to recive
	uart0_tx(temp); //loopback

	switch(temp)
	{
		case'a':IOCLR0=LED1;break;	
		case'b':IOSET0=LED1;break;
		case'c':IOCLR0=LED2;break;
		case'd':IOSET0=LED2;break;	
		case'e':IOCLR0=LED3;break;
		case'f':IOSET0=LED3;break;
		case'g':IOCLR0=LED1|LED2|LED3;break;  
		case'h':IOSET0=LED1|LED2|LED3;break;  
  
		default:uart0_tx_string("\r\n INVALID OP PLEASE ENTER IT AGAIN XD !!");
	}
 }
}
