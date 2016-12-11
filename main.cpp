#include "timer.h"


typedef struct
{
	int num;
}myparam;

void mycallback(void* args)
{
	myparam* p = (myparam*)args;
	printf("Hello World && my number is %d!\n", p->num);
}


int main(int argc, char* argv[])
{
	Timer timer;
	myparam param;
	param.num = 10;
	timer.execute(100, mycallback, (void*)&param);
	return 0;

}