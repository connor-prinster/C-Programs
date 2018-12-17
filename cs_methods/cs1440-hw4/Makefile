CXX = g++-4.8

CXXFLAGS = -Wall -Wextra -g3 -std=c++11

# Comment this line out when you *don't* want to build asan into your program.
# Changing this setting requires a complete rebuild of your project:
# the pound key isn't darkened out without this line so I added it 

# make clean && make

# the pound key isn't darkened out without this line so I added it

#valgrind --leak-check=full --show-reachable=yes ./main

#CXXFLAGS = -Wall -Wextra -g3 -std=c++11 -fsanitize=address

CPP_SRCS := $(wildcard *.cpp)
HPP_SRCS := $(wildcard *.hpp)
OBJS     := ${CPP_SRCS:.cpp=.o}

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: test run clean deepclean md5

run test: main
	./main

md5: main
	./main | md5sum

clean:
	-rm -f *.o *.d main

deepclean: clean
	-rm -f *~ cscope*.out tags cscope.files

cscope.files: $(HPP_SRCS) $(CPP_SRCS)
	find . -type f -name '*.[ch]pp' > $@

tags cscope.out: $(HPP_SRCS) $(CPP_SRCS) cscope.files
	ctags *.[ch]pp
	cscope -b -q

%.d: $(CPP_SRCS)
	$(CXX) -MM $*.cpp | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@

ifeq      "$(MAKECMDGOALS)" "test"
else ifeq "$(MAKECMDGOALS)" "run"
else ifeq "$(MAKECMDGOALS)" "clean"
else ifeq "$(MAKECMDGOALS)" "deepclean"
else ifeq "$(MAKECMDGOALS)" "md5"
else ifeq "$(MAKECMDGOALS)" "tags"
else ifeq "$(MAKECMDGOALS)" "cscope.out"
else ifeq "$(MAKECMDGOALS)" "cscope.files"
else
-include ${CPP_SRCS:.cpp=.d}
endif