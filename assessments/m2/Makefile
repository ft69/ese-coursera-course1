#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

include sources.mk

# for practice: determine OS and chose compiler
OS:=$(shell uname -s)
ifeq ($(OS),Linux)
	compileUsing := gcc
endif

TARGET = c1m2
ARCH = thumb
# Platform Overrides
ifeq ($(PLATFORM),MSP432)
 CPU = cortex-m0plus
 CC  = arm-none-eabi-$(compileUsing)
 SPECS = nosys.specs
 CFLAGS   = -mtune=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99
endif
ifeq ($(PLATFORM),HOST)
  CC  = $(compileUsing)
	CFLAGS = $(-DHOST -m$(ARCH) )
endif

LINKER_FILE = src/msp432p401r.lds
LDFLAGS  = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -c $< -o  $@

.PHONY: all
all: $(TARGET).out $(TARGET).map

.PHONY: build
build: all

OBJS = $(SOURCES:.c=.o)
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map

#.PHONY: clean
#clean:
#rm -f $(OBJS)  $(TARGET).out $(TARGET).o $(TARGET).map
