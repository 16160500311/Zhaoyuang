#include "LPC11XX.H"
const unsigned char DisTable[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void delay()
{
		uint16_t i = 5000;
		while(i--);
}

void Display(unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4)
{
		uint32_t temp_data;

	
		temp_data = DisTable[value4];
		temp_data |= 0xF00;
		temp_data &= 0x7FF;
		LPC_GPIO2->DATA = temp_data;
    delay();
	
    temp_data = DisTable[value3];
		temp_data |= 0xF00;	
		temp_data &= 0xBFF;	
		LPC_GPIO2->DATA = temp_data;
    delay();
	
		temp_data = DisTable[value2];
		temp_data |= 0xF00;	
		temp_data &= 0xDFF;	
		LPC_GPIO2->DATA = temp_data;
    delay();
	
		temp_data = DisTable[value1];
		temp_data |= 0xF00;	
		temp_data &= 0xEFF;	
		LPC_GPIO2->DATA = temp_data;
    delay();
}

int main()
{
    LPC_GPIO2 ->DIR = 0xFFF; 
	
    while(1)
    {
		
        Display(0,3,1,1);
    }
}
