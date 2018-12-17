# README

## Function Descriptions:

---

### C++ Arithmetic:
* this continuously adds two variables to one another
* the cores jumped a bit. not by much, but the bars jumped a few tick marks.
* there were no system calls
* I/O seems unaffected
* Context switches: jumps about 70 voluntary switches
* takes about .02 seconds

## Math Library:
* takes the square root of 100 over and over again
* one core took about a 10% hit
* No noticable affect on I/O
* about 49 voluntary switches
* took about .18 seconds

### new/delete char[1]:
* creates and then deletes a char array 
* no real I/O slowdowns I saw, but my second core jumped pretty high
* context switches: takes 49 voluntary and about 3 nonvoluntary switches
* takes about .3 seconds
* one core jumps about 20%, and two jump about 10%

### new char[1]:
* lots of `brk()` system calls
* takes about .2 and .3 seconds to run
* the htop, strace, and basic output started to not update as reliably as before
* context switches: takes about 288 context switches
* it takes up all the memory and kills the program if you press it enough times, the RPi apparently knows how to clean itself up if the memory overloads

### kill(0):
* constant kill($PID, SIG_0) system calls
* no slowdowns I could feel in the I/O
* context switches: took a single voluntary context switch

### kill(SIGUSR2):
* Doesn't feel slower in I/O
* makes constant system calls `kill($PID, SIGUSR2)`
* 24 nonvoluntary switches, one voluntary
* took 100% of one of my cores
* took about 3.5 seconds to run

### nanosleep(1): 
* it took about 60 seconds to run
* Observable I/O slowdowns: almost no slowdown I can see
* context switches: the context switch jumps about 5000 times a second
* No visible memory usage

### nanosleep(1000):
* Proportion of time userland vs kernal space: it took about 60 seconds to run, so it wasn't too much different than nanosleep(1)
* Observable I/O slowdowns: everything updated alright, so none I could see
* context switches: switch jumps about one thousand times a second
* makes the `nanosleep()` system call over and over
* I would have thought it would take longer than it did considering it's 1000 times more'

### nanosleep(1000000):
* it took about 1062.87 seconds on average for this to run
* everything updated consistently, so none I could see
* switch jumps about one thousand times a second
* makes the `nanosleep()` system call over and over
* It took a lot longer than I would have thought it did.

### fork():
* Took about 1107 seconds to run on average.
* keeps forking and then exiting the child processes.
* The I/O felt a bit slower than usual, but not by much
* The cores all jumped between 15% and 45% throughout
* calls fork() over and over again

### getcwd():
* only about 1 second to run
* keeps using the getcwd() system call
* no real slowdown I could see in the I/O
* context switches: only took a single context switch
* thought it would have taken a lot more switches, honestly
* no memory change, but one core jumped about 50%

### chdir():
* only about 1.5 seconds on average
* Huge slowdown I could see
* One core was all the way at 100%
* context switches: one switch
* constantly sends the chdir() system call
* it seems to work pretty much the same as getcwd().

### access(/proc/self/exe):
* about roughly 7 seconds
* Observable I/O slowdowns: nothing stopped posting to the console
* context switches: one voluntary and about 300 nonvoluntary
* same system call
* one core maxed out

### sync():
* about 27.3 to 28.5 seconds to run 
* no real I/O slowdown
* same system call over and over again
* context switches: takes about 1000 nonvoluntary switches
* pushes one of my cores to 100%

### chmod():
* sends same systemcall over and over again
* takes about 10 seconds to run
* one core maxes out
* about 2000 nonvoluntary switches

### dup2():
* takes about .45 to .48 seconds
* no observable I/O slowdown
* context switches: only increases voluntary by one
* pushed one core to 50% and then maxed it out
* keeps making the same system call

### I/O Bound Loop over /dev/mmcblk0:
* about 28 seconds to run through
* Proportion of time userland vs kernal space:  
* calls open() on one file, open() on another, reads() from the first open and writes() to the second. Then closes() both.
* context switches: one voluntary, 741 nonvoluntary
* Pushes one core to the max

---

## Tools Used:

I used `watch`, `htop`, and `strace` to analyze what's going on. 

- I used `watch` to check the switches and how they changed with `watch -n.1 grep ctxt /proc/$PID/status`

- I used `htop` to see the CPU usage and memory allocation. When one of my functions went funky I used it to kill it. The command was `htop -p $PID`

- I used `strace` to see the system calls going out of the program. The command I used was `strace -p $PID`.

The `$PID` I was referring to was the result of the `getpid()` system call. I had it print in my main menu.
