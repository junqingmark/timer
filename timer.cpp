#include "timer.h"
#include <cstdlib>


void* Timer::TimerThread(void* arg)
{
	PthreadParams* p = (PthreadParams*)arg;
	while(p->pThis->timerRunning)
	{
		p->callback(p->arg);
	}

	return ((void *)0);
}

void Timer::stopTimer()
{
	timerRunning = false;
}

Timer::Timer():timerRunning(true), num(0)
{
	startTime = getTicks();

	param = new PthreadParams();
	param->pThis = this;
	

}



Timer::~Timer()
{

}

void Timer::execute(uint32_t interval, TimerCallback callback, void* arg)
{
	param->callback = callback;
	param->arg = arg;
	if(pthread_create(&threadID, NULL, TimerThread , (void*)param) != 0)
	{
		perror("fail in pthread_create");
		exit(0);
	}

	pthread_join(threadID, NULL);
}

uint32_t Timer::getTicks()
{
	
}
