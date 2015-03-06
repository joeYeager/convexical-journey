UNAME := $(shell uname)

ifeq ("$(UNAME)", "Darwin")
	# compiler for mac machines
	CC = clang++
else
	# compiler for linux machines
	CC = g++
endif

# # compiler flags:
# #  -g    adds debugging information to the executable file
# #  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall

# This breaks some functionality in the string class
# -stdlib=libstdc++

# the build target executable:
TARGET = hull

# main source file
MAIN = main.cpp

# other source files
SOURCES = source/*.cpp

all: $(TARGET)

$(TARGET): $(MAIN)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SOURCES)
