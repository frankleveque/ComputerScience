CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -fno-exceptions \
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align \
-Wwrite-strings -Wcast-qual -Wswitch-default \
-Wswitch-enum -Wunreachable-code \
-Wuninitialized -Winit-self -march=native -Wfatal-errors -Werror 

FILENAME=morsecode.exe
SRC=morsecodegenerator.cpp

.PHONY: all clean prepare
targets:
	@echo "targets: debug release clean"
	@echo "compilers: (CC=g++) gcc, g++, clang, clang++"

all: debug release
	

prepare:
	@echo "Preparing folders"
ifeq ($(OS),Windows_NT)
	mkdir bin
else
	@mkdir -p ./bin 
endif


debug: prepare
	@echo Building target debug - $(CC)
ifeq ($(OS),Windows_NT)
	#win
else
	@mkdir -p ./bin/debug
	@$(CC) -g $(CFLAGS) $(SRC) -o ./bin/debug/$(FILENAME) 
endif


release: prepare
	@echo Building target release - $(CC)
ifeq ($(OS),Windows_NT)
	#win
else
	@mkdir -p ./bin/release
	@$(CC) -s $(CFLAGS) $(SRC) -o ./bin/release/$(FILENAME) 
endif


clean:
ifeq ($(OS),Windows_NT)
	#win
else
	rm -rf ./obj/
	rm -rf ./bin/
	rm -f *.depend
	rm -f *.layout
endif

