#pragma once

#include <chrono>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <stdio.h>
#include <errno.h>
#include <cstring>
#include <unistd.h>

class ioOperations {
public:
	ioOperations();
	~ioOperations();
	void ioLoop(bool input, const char *);
};

