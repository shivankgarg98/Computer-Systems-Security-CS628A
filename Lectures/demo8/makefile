all: utmp_read utmp_write

CFLAGS=-O3 -static

utmp_read: utmp_read.c
	gcc -o utmp_read $(CFLAGS) utmp_read.c
utmp_write: utmp_write.c
	gcc -o utmp_write $(CFLAGS) utmp_write.c
	chmod +s utmp_write
clean:
	rm -f utmp_read utmp_write
