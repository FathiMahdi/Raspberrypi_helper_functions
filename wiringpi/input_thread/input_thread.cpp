#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
using namespace std;

const int red = 21;
const int green = 17;
const int yellow = 20;
const int signal = 16;
int val = 0;
void *thread_function_1(void *value)
{
	int *x = (int *)value;	
	for(;;)
	{
		cout << "Thread 1\n";
		digitalWrite(red,HIGH);
		delay(50);
		digitalWrite(red,LOW);
		delay(50);
	}
	return (void *)0; // return a zero pointer
}

void *thread_function_2(void *value)
{
	int *x = (int *)value;	
	for(;;)
	{
		cout <<"Thread 2\n";
		digitalWrite(green,HIGH);
		delay(200);
		digitalWrite(green,LOW);
		delay(200);
	}
	return (void *)0; // return a zero pointer
}

void *thread_function_3(void *value)
{
	int *x = (int *)value;	
	for(;;)
	{
		cout <<"Thread 3\n";
		val = digitalRead(signal);
		if(val == 1)
			digitalWrite(yellow,HIGH);
		else if(val == 0)
		       digitalWrite(yellow,LOW);	
		
	}
	return (void *)0; // return a zero pointer
}
int main()
{
	void *x;
	void *ret;
	wiringPiSetupGpio();
	pinMode(red,OUTPUT);
	pinMode(green,OUTPUT);
	pinMode(yellow,OUTPUT);
	pthread_t Mythread1; // create thread object
	pthread_t Mythread2; // create thread object
	pthread_t Mythread3; // create thread object
	pthread_create(&Mythread1,NULL, &thread_function_1,&x); // create thread No.1
	pthread_create(&Mythread2,NULL, &thread_function_2,&x); // create thread No.2
	pthread_create(&Mythread2,NULL, &thread_function_3,&x); // create thread No.3
	pthread_join(Mythread1,&ret);
	pthread_join(Mythread2,&ret);
	pthread_join(Mythread3,&ret);

	return 0;
}
