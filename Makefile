CC = gcc
CFLAGS = -O2 -std=c11 -Wall -pedantic
CFLAGS_INLINE = -O2 -std=c11 -Wall -pedantic -DUSE_INLINE
LDLIBS = -lm

EXECUTABLE = primes primes-i
OBJS = primes.o error.o eratosthenes.o

.PHONY: all primes primes-i zip clean

all: $(EXECUTABLE)

primes: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

primes-i: $(OBJS)
	$(CC) $(CFLAGS_INLINE) -o $@ $^ $(LDLIBS)

primes.o: primes.c
	$(CC) $(CFLAGS) -c $^

error.o: error.c
	$(CC) $(CFLAGS) -c $^

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c $^

zip:
	zip xchalu15.zip *.c *.h Makefile

clean:
	rm -rf $(EXECUTABLE) *.o
