# Compiler options
LIB_PATH=
CC=gcc
CFLAGS=-c #-D$(GLOBAL_DEFINE_FLAGS)
LDFLAGS=-L$(LIB_PATH) -lpthread
LIBS = -lpthread
EXECUTABLE_NAME=otax

ifeq ($(TARGET_OS),LINUX) 
	LIBS += -ldl
endif

# Folders
SRC=/src
BIN=../../build
OBJ=$(BIN)/obj

# List of source files used in the projectsss
SOURCE_FILES	=	main.c

#########################################################
EXECUTABLE_FILES = $(EXECUTABLE_NAME:%=$(BIN)/%)
OBJECT_FILES     = $(SOURCE_FILES:%.c=$(OBJ)/%.o)
#########################################################

build: $(EXECUTABLE_FILES)

clean:
	rm -r -f $(BIN)/*

.PHONY: build clean

$(EXECUTABLE_FILES): $(OBJECT_FILES)
	@$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)
	@echo "Build successful!"

$(OBJECT_FILES): $(OBJ)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ $<