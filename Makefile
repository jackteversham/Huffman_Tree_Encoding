#This is a sample make file that adds extra debugging to your program.
#you will need to change it so that it knows about the structure of
#your program, which (hopefully) will not be all in one file.
#Run this Makefile by typing
# make m="Commit message" <<-- analyses, builds, commits and runs the program
# make release <<-- build a 'clean' executable without debug info
# make clean << clears out binary files.

# DO NOT just run 'make' on the command line, that will not give you sensible commit messages
# !!!!!! in git and if you don't have those in assignments you will lose points!

PROGRAM=huffmanencode

#by default CC = gcc, this will give 'undefined std::xxx errors
CC=g++  
COMPILE=-c -o
LINK=-o
#      c++11     all warnings on            
#      |         |     debug info (allows debugging with gdb)
#      |         |     |  check for out-of-bounds errors
#      V         V     V  V                  /=extra info for runtime errors
FLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer
#        fast code
#        V   /=c++11    /=still tell me about all warnings
OPTIMIZE=-O3 -std=c++11 -Wall #but do not add error checking at runtime

#the default target is debug code
debug:
	#cppcheck --enable=all $(PROGRAM).cpp #source code analysis
	#$(CC) $(FLAGS) $(COMPILE) HuffmanNode.o HuffmanNode.cpp #compile
	#$(CC) $(FLAGS) $(COMPILE) HuffmanTree.o HuffmanTree.cpp #compile
	$(CC) $(FLAGS) $(COMPILE) $(PROGRAM).o $(PROGRAM).cpp #compile
	$(CC) $(FLAGS) $(LINK) $(PROGRAM) $(PROGRAM).o #link
	
		

#and fast executable is an additional target
release:
	$(CC) $(OPTIMIZE) $(COMPILE) $(PROGRAM).o $(PROGRAM).cpp #compile for speed
	$(CC) $(OPTIMIZE) $(LINK) $(PROGRAM) $(PROGRAM).o #link

clean:
	rm -f ./test/*.o
	rm -f ./test/test_map
	rm -f *.o #clear out object files
	rm -f $(PROGRAM) #and the final executable

test: ./test/test_map
	$(CC) $(FLAGS) $(COMPILE) ./test/test_map.o ./test/test_map.cpp #compile
	$(CC) $(FLAGS) $(COMPILE) ../test_map ./test/test_map.o #link
	cd test;\
	./test_map	
