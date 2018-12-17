#pragma once

#include <iostream>
#include <chrono>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

class processOperations
{
public:
	processOperations();
	~processOperations();
	void killFunc(int signal, int pid);
	void nanosleepFunc(long delayVal);
	void forkFunc();
};
