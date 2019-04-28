all: inlineasm exploit upify

CFLAGS=-O3 -fno-stack-protector -Wno-format-security

inlineasm: inlineasm.c
	gcc $(CFLAGS) -o inlineasm inlineasm.c
exploit: exploit.c
	gcc $(CFLAGS) -o exploit exploit.c
win2: win2.c
	gcc $(CFLAGS) -o upify upify.c
clean:
	rm -f inlineasm exploit upify
