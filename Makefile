#
# Fluid
# Version: 1.5.7
#
# Use of this source code is governed by an MIT-style license that can be
# found in the LICENSE file at LICENSE.md
#

#
# CONFIGURATIONS
#

OUTNAME := libnot_rp1

ROTDIR := ./
DEPDIR := .cache
OBJDIR := .cache
OUTDIR := .
SRCDIR := .
HDRDIR := .

#
# DO NOT EDIT FORWARD
#

# Compilation settings

CC := gcc
AR := ar

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
			-Wwrite-strings -Wmissing-declarations -Wredundant-decls \
			-Winline -Wno-long-long -Wuninitialized -Wconversion -Wfatal-errors

CFLAGS ?= $(WARNINGS)

# Options

ifeq ($(VERBOSE), 1)
    SILENCER :=
else
    SILENCER := @
endif

ifeq ($(DEBUG_BUILD), 1)
    CFLAGS +=-DDEBUG_BUILD -fsanitize=address -g
endif

ifdef ($(OUT_NAME))
    OUTNAME = $(OUT_NAME)
endif

# Compilation command

all: init lib

exec: $(OUTNAME)

dexec: $(OUTNAME)
	$(SILENCER)docker build -t $(OUTNAME) .
	$(SILENCER)docker run --rm -it -v "${PWD}":"/usr/src/priv" $(OUTNAME)

lib: $(OUTNAME).a

# Automated compilator

# Compilator files

ifeq ($(TEST_BUILD), 1)
    SRCS := $(shell find $(ROTDIR)$(SRCDIR)  ! -name '*e2e.c' -name "*.c" -type f | cut -sd / -f 3- | tr '\n' ' ')
else ifeq ($(E2E_BUILD), 1)
    SRCS := $(shell find $(ROTDIR)$(SRCDIR) ! -name '*_test.c' -name "*.c" -type f | cut -sd / -f 3- | tr '\n' ' ')
else
    SRCS := $(shell find $(ROTDIR)$(SRCDIR) ! -name '*_test.c' ! -name '*_e2e.c' -name "*.c" -type f | cut -sd / -f 3- | tr '\n' ' ')
endif
OBJS := $(patsubst %, $(OBJDIR)/%, $(SRCS:c=o))
DEPS :=$(patsubst %.c, %.d, $(SRCS))

# Compilation output configurations

CFLAGS += -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

$(OUTNAME): $(OBJS)
	$(SILENCER)$(CC) $(CFLAGS) -o $(OUTDIR)/$(OUTNAME) $^

$(OUTNAME).a: $(OBJS)
	$(SILENCER)$(AR) rcs $(OUTDIR)/$(OUTNAME).a $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d
	$(SILENCER)$(CC) $(CFLAGS) -c -o $@ $<
	$(POSTCOMPILE)

# Helpers command

init:
	$(SILENCER)mkdir -p $(SRCDIR)
	$(SILENCER)mkdir -p $(OBJDIR)
	$(SILENCER)mkdir -p $(HDRDIR)

clean:
	$(SILENCER)find . -name "*.o" -type f -delete

fclean: clean
	$(SILENCER)$(RM) -r $(OBJDIR)/*
	$(SILENCER)$(RM) -r $(ROTDIR)$(OUTDIR)/$(OUTNAME)*

re: fclean all

.PHONY: re fclean clean init all lib exec dexec

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS))))
