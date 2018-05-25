.PHONY: all clean

-include ../flags.mak

PROGS = $(patsubst %.cpp,%,$(wildcard *.cpp))

# $(info $(PROGS)) # DELETE ME

all: $(PROGS)


clean:
	-rm -f $(PROGS) *.o
