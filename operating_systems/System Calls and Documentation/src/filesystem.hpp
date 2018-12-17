#pragma once

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <chrono>

class fileSystemOperations
{
public:
	fileSystemOperations();
	~fileSystemOperations();
	void getcwdFunc();
	void chdirFunc();
	void accessFunc();
	void syncFunc();
	void chmodFunc();
	void dup2Func();
};
