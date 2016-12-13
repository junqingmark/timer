//author: junqing.ma
//description: This file use a timer to calculate how many packet was send in 60 second
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int stop = 0;

void sigalarm_handler(int signo)
{
	stop = 1;
}

int main(int argc, char* argv[])
{
	struct sigaction sact;
	int num_sent = 0;

	sigemptyset(&sact.sa_mask);
	sact.sa_flags = 0;
	sact.sa_handler = sigalarm_handler;
	sigaction(SIGALRM, &sact, NULL);

	alarm(60);

	while(!stop)
	{
		send_packet();
		num_sent++;
	}

	printf("send %d packets!\n", num_sent);
	return 0;

}