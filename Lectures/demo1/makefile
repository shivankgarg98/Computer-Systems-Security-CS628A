all: stack0 stack1 auth

CFLAGS=-g -fno-stack-protector

stack0: stack0.c
	gcc -o stack0 $(CFLAGS) stack0.c
stack1: stack1.c
	gcc -o stack1 $(CFLAGS) stack1.c
auth: auth.c
	gcc -o auth $(CFLAGS) auth.c
clean:
	rm -f stack? auth
