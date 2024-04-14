#include <LPC21xx.H>
void delay_ms(unsigned int ms)
{
int a[]={15,60,30,15,15};
T0PC=0;
T0PR=a[VPBDIV]*1000-1;
T0TC=0;
T0TCR=1;
while(T0TC<ms);
T0TCR=0;
}
