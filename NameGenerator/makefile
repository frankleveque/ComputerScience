CC=gcc
CFLAGS=-std=c89 -Wall -Wextra -fno-exceptions \
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align \
-Wwrite-strings -Wcast-qual -Wswitch-default \
-Wswitch-enum -Wunreachable-code \
-Wuninitialized -Winit-self -march=native -Wfatal-errors -Werror -Ofast

FILENAME=namegenerator
SRC=namegenerator.c

.PHONY: all clean prepare
targets:
	@echo "targets: all debug release clean"
	@echo "compilers: (CC=gcc) gcc, g++, clang, clang++"



prepare:
	@echo "Preparing folders"
	@mkdir -p ./bin 
	@mkdir -p ./bin/debug 
	@mkdir -p ./bin/release 


bin/debug/$(FILENAME): prepare
	@echo Building target debug - $(CC)
	@$(CC) -g $(CFLAGS) $(SRC) -o ./bin/debug/$(FILENAME) 


bin/release/$(FILENAME): prepare
	@echo Building target release - $(CC)
	@$(CC) -s $(CFLAGS) $(SRC) -o $@

all: bin/release/$(FILENAME) bin/debug/$(FILENAME)
	@echo Done
	

clean:
	rm -rf ./obj/
	rm -rf ./bin/
	rm -f *.depend
	rm -f *.layout

