#-----------------------------------------------------------------------------
# File          : Makefile
# Author        : Wei Song  <wsong83@gmail.com>
# Created       : 13.09.2015
# Last modified : 13.09.2015
#-----------------------------------------------------------------------------
# Description :
# A GNU Make makefile to generate a shared library
#-----------------------------------------------------------------------------
# Copyright (c) 2015 by Wei Song
# License: BSD
#          See LICENSE for more details.
#------------------------------------------------------------------------------
# Modification history :
# 13.09.2015 : created
#-----------------------------------------------------------------------------

default: all
.PHONY: default all

#--------------------------------------------------------------------
# Build rules
#--------------------------------------------------------------------
CXX = g++
CXX_CFLAGS = -Iinclude

#--------------------------------------------------------------------
# Build
#--------------------------------------------------------------------
TARGETS = \
	generator \
	uniform_generator \

TARGET_OBJS = $(addsuffix .o, $(TARGETS))

$(TARGET_OBJS): %.o:src/%.cpp include/random_generator.h
	$(CXX) $(CXX_CFLAGS) -c $< -o $@

all: $(TARGET_OBJS)
