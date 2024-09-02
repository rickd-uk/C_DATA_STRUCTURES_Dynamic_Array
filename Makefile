CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
AR = ar  
ARFLAGS = rcs

LIB = libdynarray.a
OBJS = dynarray.o
MAIN = main


all: $(LIB) $(MAIN)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(MAIN): main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L. -ldynarray

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB) main.o $(MAIN)

.PHONY: all clean
