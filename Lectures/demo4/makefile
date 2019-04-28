all: auth fmtstring

CFLAGS=-O3

auth: auth.c
	gcc -o auth $(CFLAGS) auth.c
fmtstring.c: fmtstring.c
	gcc -o fmtstring $(CFLAGS) fmtstring.c
clean:
	rm -f *auth fmtstring
