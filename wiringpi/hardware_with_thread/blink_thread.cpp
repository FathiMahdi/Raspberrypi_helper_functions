#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
using namespace std;

void *thread_function_1(void *value)
{
	int *x = (int *)value;	
	for(;;;)
	{
		cout << "Thread 1\n";
		digitalWrite(*x,HIGH);
		delay(1000);
		digitalWrite(*x,LOW);
		delay(1000);
	}
	return (void *)0; // return a zero pointer
}

void *thread_function_2(void *value)
{
	int *x = (int *)value;	
	for(;;;)
	{
		cout <<"Thread 2\n";
		digitalWrite(*x,HIGH)
		delay(1000);
		digitalWrite(,LOW);
		delay(1000);
	}
	return (void *)0; // return a zero pointer
}

int main()
{
	int x = 0;
	int green = 17;
	int red = 21;
	void *ret;
	pthread_t Mythread1; // create thread object
	pthread_t Mythread2; // create thread object
	pthread_create(&Mythread1,NULL, &thread_function_1,&red); // create thread No.1
	pthread_create(&Mythread2,NULL, &thread_function_2,&green); // create thread No.2
	pthread_join(Mythread1,&ret);
	pthread_join(Mythread2,&ret);

	return 0;
}
