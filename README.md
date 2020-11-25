# simple_shell
This a proyect of Foundations - Low-level programming & Algorithm  Linux and Unix system pr\
     ogramming
This is a simple_shell

## Resources:books:

Read or watch:
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)

## Learning Objectives:bulb:
What you should learn from this project:

* Write your own Shell function.
* Team work.
* learn about the PATH and some system call
* Learn about how a shell works internally

## Initial Requirements for the project
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded 

## Authorized functions and macros
|     Funtions  |             MAN               |
|---------------|-------------------------------|
|   `access`    |       (man 2 access)
|   `chdir`     |        (man 2 chdir)
|   `close`     |        (man 2 close)
|   `closedir`  |     (man 3 closedir)
|   `execve`    | (man 2 execve)
|   `exit`      |(man 3 exit)
|   `_exit`     |(man 2 _exit)
|   `fflush`    |(man 3 fflush)
|   `fork`      |(man 2 fork)
|   `free`      |(man 3 free)
|   `getcwd`    |(man 3 getcwd)
|   `getline`   |(man 3 getline)
|   `getpid`    |(man 2 getpid)
|   `isatty`    |(man 3 isatty)
|   `kill`      |(man 2 kill)
|   `malloc`    |(man 3 malloc)
|   `open`      |(man 2 open)
|   `opendir`   |(man 3 opendir)
|   `perror`    |(man 3 perror)
|   `read`      |(man 2 read)
|   `readdir`   |(man 3 readdir)
|   `signal`    |(man 2 signal)
|   `stat`      |(__xstat) (man 2 stat)
|   `lstat`     |(__lxstat) (man 2 lstat)
|   `fstat`     |(__fxstat) (man 2 fstat)
|   `strtok`    |(man 3 strtok)
|   `wait`      |(man 2 wait)
|   `waitpid`   | (man 2 waitpid)
|   `wait3`     |(man 2 wait3)
|   `wait4`     |(man 2 wait4)
|   `write`     |(man 2 write)

### Example of test file that can be used:

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Compilate files are compiled this way:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Authors
* **Nelson Arevalo** - [NelsonarevaloF](https://github.com/NelsonarevaloF/)
* **Jhon Arias** - [7honarias](https://github.com/7honarias/)

