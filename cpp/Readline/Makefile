## Makefile Template.

## Directory Configuration
# .
# |-- Makefile (This file)
# |-- build/
# |   |-- target file.
# |    `-- obj/
# |        `-- object files.
# |-- sample/
# |    `-- sample data files.
# |-- include/
# |    `-- header files.
#  `-- source/
#      `-- source files & header files.

## Directory defines
BUILDDIR = ./build
OBJDIR   = $(BUILDDIR)/obj
SRCDIR   = ./src
INCDIR   = ./include
LIBDIR   = #-L

## Target name
TARGET   = $(BUILDDIR)/a.out

## Arguments for target
ARGS     = "sample/random_pts.dat"

## Compiler options
CC       = gcc
CFLAGS   = -g -O2 -Wall
CXX      = g++
CXXFLAGS = -std=c++0x -g -O0 -Wall
LDFLAGS  = #-no-pie

## Files
SRCS := $(shell find $(SRCDIR) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)
LIBS := #-lboost_system -lboost_thread

## Include files
INCLUDE  := $(shell find $(INCDIR) -type d)
INCLUDE  += $(shell find $(SRCDIR) -type d)
INCLUDE  := $(addprefix -I,$(INCLUDE))

## Linker options
HEADFLAGS := $(INCLUDE) -MMD -MP
LDFLAGS  += $(LIBDIR) $(LIBS)

## Target
default: all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

## assembly
$(OBJDIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

## C source
$(OBJDIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(HEADFLAGS) $(CFLAGS) -c $< -o $@

## C++ source
$(OBJDIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(HEADFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean rebuild

## Clean command
clean:
	$(RM) -r $(BUILDDIR)

## Build after clean command
rebuild:
	make clean && make

## Run command
run: $(TARGET)
	$(TARGET) $(ARGS)

## Check command for memory leak
debug: $(TARGET)
	valgrind --leak-check=full $(TARGET) $(ARGS)

-include $(DEPS)

MKDIR_P = mkdir -p
