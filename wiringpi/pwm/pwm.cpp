#include <iostream>
#include <wiringPi.h>

using namespace std;



const int pwm_pin = 12;
const float divisor = 7.5;
const int range = 256;


void pwm(int pin)
{
	

	for(int i=0;i<range;i++)
	{

		pwmWrite(pwm_pin,i);
		delay(10);
	}

	for(int j = range ; j>=0 ; j-- )
	{

		pwmWrite(pwm_pin,j);
		delay(10);
	}
}


int main()
{
	wiringPiSetupPhys();
	pinMode(pwm_pin,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(range);
	pwmSetClock(divisor);
	while(1)
		pwm(pwm_pin);
	return 0;



}
