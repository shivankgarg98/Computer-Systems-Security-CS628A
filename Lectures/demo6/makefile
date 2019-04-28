all: myname myname2 logtime

CFLAGS=-O3

myname: myname.c
	gcc -o myname $(CFLAGS) myname.c
myname2: myname2.c
	gcc -o myname2 $(CFLAGS) myname2.c
logtime: logtime.c
	gcc -o logtime $(CFLAGS) logtime.c
clean:
	rm -f myname myname2 logtime ptrace ptrace2 time.log
