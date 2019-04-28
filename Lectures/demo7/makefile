all: logmsg logmsg2 ptrace ptrace2 trsudo

CFLAGS=-g

logmsg: logmsg.c
	gcc -o logmsg $(CFLAGS) -fno-stack-protector logmsg.c
	chmod +s logmsg
logmsg2: logmsg2.c
	gcc -o logmsg2 $(CFLAGS) -fno-stack-protector logmsg2.c
	chmod +s logmsg2
ptrace: ptrace.c
	gcc -o ptrace $(CFLAGS) ptrace.c
ptrace2: ptrace2.c
	gcc -o ptrace2 $(CFLAGS) ptrace2.c
trsudo: trsudo.c
	gcc -o trsudo $(CFLAGS) trsudo.c
clean:
	rm -f logmsg logmsg2 ptrace ptrace2 time.log msg.log
