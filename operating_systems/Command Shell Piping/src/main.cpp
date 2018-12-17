#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <typeinfo>
#include <vector>
#include <sstream>
#include <chrono>
#include <iomanip>

//the globals *crosses self*
bool quittingTime = true;
//holds string versions of the commands used
std::vector<std::string> history;
// will hold the total time the process has been running
double totalTime = 0;

//helpful functions
std::vector<char *> parseCmds(std::string);
std::vector<std::string> parsePipes(std::string);
void printHistoryHeader();
void printAllHistory();
void printSomeHistory(std::string);
void makeHistory(std::string);
void increaseRunningTime(double difference);
void printTime();
void shell();
void piping(std::vector<std::vector<char*>> parsedCommands);
void forkItAll(int in, int out, std::vector<char *> commands);

void ctrlCatch(int a) {
//	std::cout << "\n";
//	shell();
}

// since we're inserting all the data in the program, no need 
// for argc or argv which is nice, tbh
int main() {
	signal(SIGINT, ctrlCatch);
	// for debugging on the rPI since I killed it one time.
	std::cout << "pid: " << getpid() << std::endl;
	while (quittingTime) {
		shell();
	}
	return 0;
}

void shell() {
	std::vector<std::vector<char*>> parsedCommands; //list of commands 
	std::vector<std::string> pipeVec; // will hold things between pipes

	parsedCommands.clear();	//makes sure vectors are clean
	pipeVec.clear();

	std::string input; // holds input
	char cwd[256]; // setting a char for holding the cwd

	std::cout << "[" << getcwd(cwd, sizeof(cwd)) << ":] "; // taking input
	getline(std::cin, input);

	pipeVec = parsePipes(input); // gets all the commands passed

	for (int i = 0; i < pipeVec.size(); i++) {
		// pushback the parsedCommands vector
		// parses the input from one of the pipevec commands in a for-loop
		parsedCommands.push_back(parseCmds(pipeVec[i]));
	}

	std::string potentiallyCd;
	if(parsedCommands.size() > 0) {
		std::string checkCd(parsedCommands[0][0]); // checks the first pipes first spot
		potentiallyCd = checkCd;
	}
	else {
		std::string potentiallyCd = " ";
	}

	//exit on "exit"
	if (input == "exit") {
		quittingTime = false;
	}
	//if user wants to see all the history
	else if (input == "history") {
		printAllHistory(); //print all the history minus the "history" command just used
		makeHistory(input);
	}
	//user wants specific history
	else if (input[0] == '^') {
		makeHistory(input);
		printSomeHistory(input);
	}
	//user wants to see total time running through
	else if (input == "ptime") {
		makeHistory(input);
		printTime();
	}
	else if (potentiallyCd == "cd") {
		chdir(parsedCommands[0][1]); //hopefully the right one right after cd in command
	}
	// user wants to do stuff
	else if (parsedCommands.size() > 0) {
		auto initTime = std::chrono::high_resolution_clock::now(); // starting time
		piping(parsedCommands); // go to the piping stuff
		auto finalTime = std::chrono::high_resolution_clock::now();	// final times
		std::chrono::duration<double> dur = initTime - finalTime;
		increaseRunningTime(dur.count());
	}
}

void piping(std::vector<std::vector<char*>> parsedCommands) {
	pid_t pid; //git the pid lol
	pid = fork(); //fork it up
	int statLoc; //whatever this means
	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0) {
		int in = 0;	//get input from the original fd
		int fd[2]; // will hold the file descriptors
		int numCmd = parsedCommands.size();
		int i = 0; // need this after the for loop for the final query
		// pipe for the amount of commands passed
		for (i = 0; i < numCmd - 1; i++) {
			pipe(fd); //new pipe for fd[]
			// pass in the current write spot and read spot and cmd vector #i
			forkItAll(in, fd[1], parsedCommands[i]); // not explicit, just goes through this
			close(fd[1]); //close write end of pipe
			in = fd[0]; //keep read end of pipe open
		}
		if (in != 0) {
			dup2(in, 0);
		}
		execvp(parsedCommands[i][0], &parsedCommands[i][0]);
	}
	else {
		waitpid(pid, &statLoc, WUNTRACED);
	}
}

void forkItAll(int in, int out, std::vector<char *> commands) {
	pid_t pid;
	int statLoc; // something statloc?

	pid = fork();
	// something stinketh
	if (pid < 0) {
		perror("Fork Failed"); //print error
		exit(1); //exit with error
	}
	// is child, will use it
	else if (pid == 0) {
		if (in != 0) {
			dup2(in, 0);
			close(in);
		}
		if (out != 1) {
			dup2(out, 1);
			close(out);
		}
		if (execvp(commands[0], &commands[0])) {
			perror(commands[0]);
			exit(1);
		}
	}
	// else is the parent, wait for it
	else {
		waitpid(pid, &statLoc, WUNTRACED);
	}

}

std::vector<char *> parseCmds(std::string input) {
	std::istringstream ss(input); //create the sstream object
	std::string tmp; //just the token to be used in this
	std::vector<char *> cmd; //create the vector containing the whole vector

	//while there is stuff in the input, put in a vector
	while (std::getline(ss, tmp, ' ')) {
		cmd.push_back(strdup(tmp.c_str()));
	}

	cmd.push_back(NULL); //there must be a NULL at the end so I'll add it

	return cmd; //return the vector
}

// puts all the functions with a pipe into here
std::vector<std::string> parsePipes(std::string input) {
	makeHistory(input); //input the passed command (total) into the history vector

	std::vector<std::string> piped; //for putting stuff into the piped vector
	std::istringstream ss(input);
	std::string tmp;

	// using pipes as delimiters parse it
	while (std::getline(ss, tmp, '|')) {
		piped.push_back(tmp);
	}

	for (int i = 0; i < piped.size(); i++) {
		// if the first char is a space, remove it somehow
		if (piped[i][0] == ' ') {
			std::string replacement = "";
			for (int j = 0; j < piped[i].size() - 1; j++) {
				replacement += piped[i][j + 1];
			}
			piped[i] = replacement;
		}
	}

	return piped;
}

void makeHistory(std::string newCommand) {
	history.push_back(newCommand); //push back the vector with the new command inputted 
}

//prints out all history
void printAllHistory() {
	int vecSize = history.size(); //finds size of history vector

	printHistoryHeader(); //print history header, self-explanatory

	//print all stuff in the history
	for (int i = 0; i < vecSize; i++) {
		std::cout << i + 1 << ": " << history[i] << std::endl;
	}
	std::cout << std::endl;
}

//prints out a single piece of history
void printSomeHistory(std::string input) {
	//the number will at least start at cmd[2] as cmd[0] is '^' and cmd[1] is ' '
	if (input[1] != ' ') {
		std::cout << "\nincorrect format, should be '^ <number>'" << std::endl;
	}
	else {
		std::istringstream ss(input); //create the sstream object
		std::string tmp; //just the token to be used in this

		std::vector<std::string> lookingForNumber; //create the vector containing the whole vector

		//while there is stuff in the input, put in a vector
		while (std::getline(ss, tmp, ' ')) {
			lookingForNumber.push_back(tmp);
		}

		int maxPos = history.size(); //this is the max number we can access in the vector

		int searchPos = std::stoi(lookingForNumber[1]); //the position in the history we're looking for

		//if our search is within the boundaries of the history vector
		if (searchPos <= maxPos && searchPos > 0) {
			printHistoryHeader();
			std::cout << searchPos << ": " << history[searchPos - 1] << std::endl;
		}
		//searching outside our boundaries
		else {
			printHistoryHeader();
			std::cout << "SEARCH POSITION OUT OF BOUNDS" << std::endl;
		}
		std::cout << std::endl;
	}
}

void printHistoryHeader() {
	std::cout << "\n=== COMMAND HISTORY ===\n";
}

void increaseRunningTime(double difference) {
	totalTime += difference;
}

void printTime() {
	double nonNegDur = -1 * totalTime;
	std::cout << "\t Time spent executing child processes: ";
	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	std::cout << nonNegDur;
	std::cout << " seconds" << std::endl;
}
