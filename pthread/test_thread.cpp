#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *thread_function_1(void *value)
{
	int *x = (int *)value;	
	for(int i=0;i<=10;i++)
	{
		*x+=1;
		cout <<"Thread 1\n";
		usleep(1000);
	}
	return (void *)0; // return a zero pointer
}

void *thread_function_2(void *value)
{
	int *x = (int *)value;	
	for(int i=0;i<=10;i++)
	{
		*x+=1;
		cout <<"Thread 2\n";
		usleep(1000);
	}
	return (void *)0; // return a zero pointer
}

int main()
{
	int x = 0;
	void *ret;
	pthread_t Mythread1; // create thread object
	pthread_t Mythread2; // create thread object
	pthread_create(&Mythread1,NULL, &thread_function_1,&x); // create thread No.1
	pthread_create(&Mythread2,NULL, &thread_function_2,&x); // create thread No.2
	pthread_join(Mythread1,&ret);
	pthread_join(Mythread2,&ret);

	for(int i=0;i<10;i++)
	{
		cout<<"The value of x = "<<x++<<"\n";
		usleep(10);
	}
	cout<<"return fron pthread_jion:" <<ret <<endl;

	return 0;
}
