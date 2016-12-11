#ifndef _TIMER_H_
#define _TIMER_H_
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>

class Timer
{
public:
	typedef void (*TimerCallback)(void*);
	typedef struct
	{
		Timer* pThis;
		TimerCallback callback;
		void* arg;

	}PthreadParams;

	
	Timer();
	~Timer();

	void execute(uint32_t interval, TimerCallback callback, void* arg);
	uint32_t getTicks();
	void stopTimer();
	static void* TimerThread(void* arg);

private:
	uint32_t startTime;
	pthread_t threadID;
	bool timerRunning;
	int num;
	PthreadParams* param;
};


#endif