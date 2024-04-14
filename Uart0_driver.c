#include<LPC21xx.H>
#include<stdio.h>
#include"header.h"
#define THRE ((U0LSR>>5)&1)
/*UART_INIT*/
void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int pclk=a[VPBDIV]*1000000;
unsigned int result=0;
result=pclk/(16*baud);

PINSEL0|=0x05;                 // p0.0-->TXD0 //p0.1-->RXD0
U0LCR=0x83;
U0DLL=result&0XFF;           //MASKING AND EXTRACTING LOWER 8 BITS
U0DLM=(result>>8)&0XFF;     //MASKING AND EXTRACTING HIGHER 8 BITS
U0LCR=0X03;                //LOCKING THE BAUD RATE AND SENDING 8 BIT OF DATA
}

/*UART0 1bit Transfer Data*/
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}


/*UART0 1byte Transfer Data*/
void uart0_tx_string(char *ptr)
{
 while(*ptr)
 {
 //U0THR=*ptr;
 //while(THRE==0); 
 uart0_tx(*ptr++);
 //ptr++;
 }
}
///////////////// UART0_RX ////////////////////////////////////////

#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}

///////////////*UART0 STRING recive*//////////////////////////////
void uart0_rx_string(char *ptr,unsigned int max_bytes)
{
unsigned int i;
for(i=0;i<max_bytes;i++)
{
while(RDR==0);
ptr[i]=U0RBR;
uart0_tx(ptr[i]);
if(ptr[i]=='\r')
break;
}
ptr[i]='\0';
}

