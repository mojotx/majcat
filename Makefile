OS=$(shell uname -s)
CFLAGS=-O -Wall -Wextra -fstack-protector-strong -pipe -MMD
ifeq ($(OS), Darwin)
	CFLAGS+=-arch x86_64 -mmacosx-version-min=12.0
endif
RM=rm -frv
SRCS=main.c process.c iscomment.c
OBJS=$(SRCS:.c=.o)
DEPS=$(SRCS:.c=.d)
.PHONY: all clean

all: majcat

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

majcat: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) numcat core *.o

squeaky-clean: clean
	$(RM) *.d

deps: $(DEPS)

-include $(DEPS)
