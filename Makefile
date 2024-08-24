# Default name and Arguments for the APP
APP ?= main
ARGS ?= 

#Vars
CC = gcc
EXTSRC = c
EXTINC = h

#Flags
CFLAGS = -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-paremeter -Wno-unused-variable -Wshadow
LDFLAGS = -lcrypt -lcs50 -lm

# Directories
APPDIR = app
INCDIR = include
LIBDIR = lib
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Application name verification
ifeq ($(APP),)
$(error No app specified. Use: make APP=<app_name>)
endif

# Find all source files (.$(EXTSRC))
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/$(APP).$(EXTSRC))

# Generate a list of object files (.o) from the source file names
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES))) \
           $(patsubst $(APPDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(APPDIR)/%.$(EXTSRC), $(SOURCES)))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: clean folder exe

#Create directory
.PHONY: folder
folder:
ifeq ($(OS),Windows_NT)
	@ if not exist "$(BINDIR)" mkdir $(BINDIR)
	@ if not exist "$(OBJDIR)" mkdir $(OBJDIR)
else
	@ if [ ! -d "$(BINDIR)" ]; then mkdir -p $(BINDIR); fi
	@ if [ ! -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi
endif

# Compile exe
.PHONY: exe
exe:  $(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) $(LDFLAGS) -o $(BINDIR)/$(APP)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Run exe
.PHONY: run
run:
	@ $(BINDIR)/$(APP) $(ARGS)

# Clean BUILD files
.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	@ if exist "$(BUILDDIR)" rd /s /q $(BUILDDIR)
else
	@ if [ -d "$(BUILDDIR)" ]; then rm -rf $(BUILDDIR); fi
endif
