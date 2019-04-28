Setup
=====

    $ ls
    hello  hello.c  hello.py  test
    $ cat hello.c 
    #include <stdio.h>

    int main()
    {
        printf("hello, world!\n");
        return 0;
    }

Experiment 1: Binaries
======================

    $ ls -l hello
    --wx--x--x 1 pramod pramod 8304 Jan 17 00:47 hello
    $ ./hello
    hello, world!

Lesson, we can execute programs without read permissions as long as we have execute permissions.

Experiment 2: Scripts
=====================

    $ cat hello.py 
    #! /usr/bin/python3

    print ("hello, world!")
    
    $ ls -l hello.py 
    -r-xr-xr-x 1 pramod pramod 45 Jan 17 00:48 hello.py

Make script unexecutable but keep readable.

    $ chmod -x hello.py 
    $ ls -l hello.py 
    -r--r--r-- 1 pramod pramod 45 Jan 17 00:48 hello.py

We can't execute as ./hello.py.

    $ ./hello.py
    bash: ./hello.py: Permission denied

But we can execute by passing it to the python3 interpreter.

    $ python3 hello.py 
    hello, world!

Only executable is not enough for script files, because the process python3 must be able to read the script.

    $ chmod -r hello.py 
    $ ls -l hello.py 
    ---------- 1 pramod pramod 45 Jan 17 00:48 hello.py
    $ chmod +x hello.py 
    $ ./hello.py 
    /usr/bin/python3: can't open file './hello.py': [Errno 13] Permission denied

