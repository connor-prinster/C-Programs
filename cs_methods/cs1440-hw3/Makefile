CXX = g++-4.8

CXXFLAGS = -Wall -Wextra -g3 -std=c++11

CPP_SRCS := $(wildcard *.cpp)
HPP_SRCS := $(wildcard *.hpp)
OBJS     := ${CPP_SRCS:.cpp=.o}

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: test run clean deepclean

run test: main
	./main

clean:
	-rm -f *.o *.d main

deepclean: clean
	-rm -f *~ cscope*.out tags cscope.files

cscope.files: $(HPP_SRCS) $(CPP_SRCS)
	find . -type f -name '*.[ch]pp' > $@

tags cscope.out: $(HPP_SRCS) $(CPP_SRCS) cscope.files
	ctags *.[ch]pp
	cscope -b -q

Database.o: Database.cpp
	@$(ZW5jb2RlZCBtZXNzYWdl)
	time $(CXX) $(CXXFLAGS) -c $<
	@echo

%.d: $(CPP_SRCS)
	$(CXX) -MM $*.cpp | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@

ifeq      "$(MAKECMDGOALS)" "clean"
else ifeq "$(MAKECMDGOALS)" "test"
else ifeq "$(MAKECMDGOALS)" "tags"
else ifeq "$(MAKECMDGOALS)" "cscope.out"
else ifeq "$(MAKECMDGOALS)" "cscope.files"
else
-include ${CPP_SRCS:.cpp=.d}
endif

define ZW5jb2RlZCBtZXNzYWdl
echo XyAuIF8gIF8gICAgXyAgXyBfX19fIF9fXyAgICBfX19fIF8gICAgX19fXyBfX19fIF8gIF8gXyBf | base64 -d
echo ICBfIF9fX18gICAgX19fXyBfX19fIF9fX18gICAgCnwgJyB8XC98ICAgIHxcIHwgfCAgfCAgfCAg | base64 -d
echo ICAgW19fICB8ICAgIHxfX3wgfCAgICB8Xy8gIHwgfFwgfCB8IF9fICAgIHwgIHwgfF9fXyB8X19f | base64 -d
echo ICAgIAp8ICAgfCAgfCAgICB8IFx8IHxfX3wgIHwgICAgIF9fX10gfF9fXyB8ICB8IHxfX18gfCBc | base64 -d
echo XyB8IHwgXHwgfF9fXSAgICB8X198IHwgICAgfCAgICAuLi4KXyAgXyBfICAgXyAgICBfX19fIF9f | base64 -d
echo X18gX19fICBfX19fIC4gX19fXyAgIF9fX18gX19fXyBfICBfIF9fXyAgXyBfICAgIF8gXyAgXyBf | base64 -d
echo X19fIAp8XC98ICBcXy8gICAgIHwgICAgfCAgfCB8ICBcIHxfX18gJyBbX18gICAgfCAgICB8ICB8 | base64 -d
echo IHxcL3wgfF9fXSB8IHwgICAgfCB8XCB8IHwgX18gCnwgIHwgICB8ICAgICAgfF9fXyB8X198IHxf | base64 -d
echo Xy8gfF9fXyAgIF9fX10gICB8X19fIHxfX3wgfCAgfCB8ICAgIHwgfF9fXyB8IHwgXHwgfF9fXSAK | base64 -d
endef
