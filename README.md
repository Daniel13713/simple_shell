# Simple Shell

This project emulate the [Unix Shell](https://en.wikipedia.org/wiki/Unix_shell) behavior, in specific the Bourne Shell [(sh)](https://en.wikipedia.org/wiki/Bourne_shell#:~:text=The%20Bourne%20shell%20(%20sh%20)%20is,interpreter%20for%20computer%20operating%20systems.&text=Although%20it%20is%20used%20as,considered%20to%20produce%20structured%20programs.), using C program language 
### Installation

Clone this repository in your local machine 

```bash
git clone https://github.com/Daniel13713/simple_shell.git
```

### Compilation

You need the gcc [4.8.4] version or upper gcc, with the command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

### Interactive mode
The shell takes the commands from the STANDARD INPUT with getline function, execute them and is ready to read a new line. 
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
### No-Interactive mode
In this mode, the shell does not display another line but it read the comand passed through a pipeline with echo command
```bash
$ echo "ls" | ./hsh
auxfuncs.c  _getenv.c         main.c         _realloc.c 
duriv.h     getpathcommand.c  no_builtins.c  test
executer.c  hsh               reader.c       tokennizer.c
_exit.c     infinite_loop.c   README.md      _which.s

$ cat test
ls
which ls

$ cat test | ./hsh
README.md   _which.s    getpathcommand.c  no_builtins.c
_exit.c     auxfuncs.c  hsh               reader.c
_getenv.c   duriv.h     infinite_loop.c   test
_realloc.c  executer.c  main.c            tokennizer.c
/usr/bin/ls

$
```

## Man
**Man Page**
To see the *man page* of our **shell** use:

```bash
man ./man_1_simple_shell
```
## Flowchart 
The logic of the program is show here

[Image](https://github.com/Daniel13713/simple_shell/blob/master/Simple%20shell%20attempt%201.drawio.png)

## Authors
- [Felipe Rivas](https://github.com/ferivb)
- [Daniel Duarte](https://github.com/Daniel13713)

## License
[MIT](https://choosealicense.com/licenses/mit/)
