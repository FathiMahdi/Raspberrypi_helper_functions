#include <iostram>
#include <wiringPi.h>
using namespace std;


void blink(int gpio)
{
	digitalWrite(gpio,HIGH);
	delay(1000);
	digitalWrite(gpio,LOW);
	delay(1000);

}

int main()
{


	wiringPiSetupGpio();
	pinMode(21,OUTPUT);
	while(1)
	{
		blink(21);
	}


	return 0;
}


