all: perrno

perrno: print_errno.c
	gcc -g -O0 -Wall print_errno.c -o perrno


.PHONEY: clean
clean:
	-rm *~
	-rm perrno


