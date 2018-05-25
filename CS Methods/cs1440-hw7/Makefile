-include flags.mak

CPP_SRCS := $(wildcard *.cpp)
HPP_SRCS := $(wildcard *.hpp)
OBJS     := ${CPP_SRCS:.cpp=.o}

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

.PHONY: test run clean deepclean examples

run test: main
	./main

examples:
	$(MAKE) -C $@

clean:
	-rm -f *.o *.d main

deepclean: clean
	-rm -f *~ cscope*.out tags cscope.files
	-$(MAKE) -C examples clean

cscope.files: $(HPP_SRCS) $(CPP_SRCS)
	find . -type f -name '*.[ch]pp' > $@

tags cscope.out: $(HPP_SRCS) $(CPP_SRCS) cscope.files
	ctags *.[ch]pp
	cscope -b -q

%.d: $(CPP_SRCS)
	$(CXX) $(CXXFLAGS) -MM $*.cpp | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@

ifeq      "$(MAKECMDGOALS)" "clean"
else ifeq "$(MAKECMDGOALS)" "deepclean"
else ifeq "$(MAKECMDGOALS)" "test"
else ifeq "$(MAKECMDGOALS)" "tags"
else ifeq "$(MAKECMDGOALS)" "examples"
else ifeq "$(MAKECMDGOALS)" "cscope.out"
else ifeq "$(MAKECMDGOALS)" "cscope.files"
else
-include ${CPP_SRCS:.cpp=.d}
endif
