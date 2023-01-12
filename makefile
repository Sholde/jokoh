################################################################################
# Makefile variables
################################################################################
# Compiler and flags
CC=gcc
CFLAGS=-Wall -Wextra -DNDEBUG
OFLAGS=-O3 -march=native -funroll-loops
DFLAGS=-g
IFLAGS=
LFLAGS=

# Directories
SRC=src
OBJ=obj
BIN=bin

# General
VERBOSE=@
INSTALL_PREFIX=/usr/local

# Target
TARGET=libjokoh.so

################################################################################
# Default target: make all
################################################################################
.PHONY: all
all: prepare $(BIN)/$(TARGET) example

.PHONY: prepare
prepare:
	@ echo "-- Creating directories"
	$(VERBOSE) mkdir -p $(SRC) $(OBJ) $(BIN)

$(BIN)/$(TARGET): $(SRC)/jokoh.c $(SRC)/jokoh.h
	@ echo "-- Building the shared library"
	$(VERBOSE) $(CC) -fPIC -shared $(CFLAGS) $(OFLAGS) $(DFLAGS) $(IFLAGS) $^ -o $@

.PHONY: example
example:
	@ echo "-- Building the example"
	$(VERBOSE) $(CC) $(CFLAGS) $(OFLAGS) examples/main.c -ljokoh -L./$(BIN) -I./$(SRC) -o $(BIN)/example.elf

################################################################################
# Install/Uninstall: install/uninstall the library
################################################################################
.PHONY: install
install:
	@ echo "-- Installing the shared library in $(INSTALL_PREFIX)"
	$(VERBOSE) mkdir -p $(INSTALL_PREFIX)/lib
	$(VERBOSE) mkdir -p $(INSTALL_PREFIX)/include
	$(VERBOSE) cp -iv ./$(BIN)/$(TARGET) $(INSTALL_PREFIX)/lib
	$(VERBOSE) cp -iv ./$(SRC)/jokoh.h $(INSTALL_PREFIX)/include

.PHONY: uninstall
uninstall:
	@ echo "-- Uninstalling the shared library in $(INSTALL_PREFIX)"
	$(VERBOSE) rm -iv $(INSTALL_PREFIX)/lib/$(TARGET)
	$(VERBOSE) rm -iv $(INSTALL_PREFIX)/include/jokoh.h

################################################################################
# Clean: removes everything that can be rebuilt
################################################################################
.PHONY: clean
clean:
	@ echo "-- Cleaning building files"
	$(VERBOSE) rm -Rf *~ **/*~ $(OBJ) $(BIN) $(TARGET)

################################################################################
# User help menu
################################################################################
.PHONY: help
help:
	@ echo "################################################################### ";
	@ echo "This is the Makefile for the execution of $(TARGET)";
	@ echo "make help shows this extra information";
	@ echo "";
	@ echo "Usage: make target VAR=";
	@ echo "target is one of:";
	@ echo "  help                      : show this help message";
	@ echo "  all                       : build the project";
	@ echo "  clean                     : removes everything that can be rebuilt";
	@ echo "  prepare                   : create empty directories for objects and binaries";
	@ echo "  install                   : install the shared library in INSTALL_PREFIX";
	@ echo "  uninstall                 : uninstall the shared library in INSTALL_PREFIX";
	@ echo "VAR can be one of:";
	@ echo "  VERBOSE                   : by default it is set to '@' and disables verbosity, set it to '' to enable verbosity";
	@ echo "  INSTALL_PREFIX            : by default it is defined as '/usr/local', it specifies the directory where the shared library will be installed";
