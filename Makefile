#Makefile template from Lazyfoo Productions
#OBJS specifies which files to compile as part of the project
OBJS = baoGen2.c

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -std=c11 -O3

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lm

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = baogen2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
