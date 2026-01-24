

# Quick reference - allowed functions

## Why ?

Simply because I do not wish to go to the man every second to get simple information. I'm kind of goldfish.

Since this is meant to stay a "Quick reference", links are present to easily get back more detailed information later. This should come handy in the future !

printf
malloc
free

## Syscalls list

https://man7.org/linux/man-pages/man2/syscalls.2.html

## GNU Readline library

https://man7.org/linux/man-pages/man3/readline.3.html
https://tiswww.cwru.edu/php/chet/readline/readline.html

Read a new line, allows to get the history back.

- readline
- rl_clear_history
- rl_on_new_line
- rl_replace_line
- rl_redisplay

## GNU History library
https://tiswww.cwru.edu/php/chet/readline/history.html

add_history : add an entry (a line) to the history.

## File Descriptors, open, read, write

- access (sys) : determine accessibility of a file descriptor.
- open (sys) : Open a file. The return value of open() is a file descriptor.
- read (sys) : Read from a file descriptor.
- write (sys) :
- close (sys) : close a file descriptor.

## Process management

fork : create a child process.

https://man7.org/linux/man-pages/man2/fork.2.html

wait, waitpid : wait for process to change state.

- wait : Suspends execution of the calling thread until one of its children terminates.
- waitpid : Suspends execution of the calling thread until a child specified by pid argument has changed state.


wait3, wait4 : wait for process to change state, BSD style but additionally return resource usage information about the child in the structure pointed to by `rusage`.

> From [man 2 wait3] : These functions are nonstandard; in new programs, the use of `waitpid(2)` or `waitid(2)` is preferable.


- wait3 : waits of any child.
- wait4 : can be used to select a specific child, or children, on which to wait.

exit : terminate the calling process.

## Signal management

signal : signal management. The `sigaction()` function provides a more comprehensive and reliable mechanism for controlling signals; new applications should use `sigaction()` rather  than `signal()`.

### Recommended signal management

https://man7.org/linux/man-pages/man2/sigaction.2.html

- sigaction (sys) : examine and change a signal action
- sigemptyset : initializes the signal set given by set to empty, with all signals excluded from the set.
- sigaddset : add signal `signum` from set.

Returns : sigemptyset(), sigfillset(), sigaddset(), and sigdelset() return 0 on success and -1 on error.

kill : can be used to send any signal to any process group or process.

getcwd : get current working directory. Copies an absolute pathname of the current working directory to the array pointed to by buf, which is of length size.

chdir : changes the current working directory of the calling process to the directory specified in path.

## File status syscalls

Stat, fstat, lstat : get file status

https://man7.org/linux/man-pages/man2/lstat.2.html

- stat (sys) : retrieve information about the file pointed to by path.
- lstat (link) : identical to stat(), except that if path is a symbolic link, then it returns information about the link itself, not the file that the link refers to.
- fstat (fd) : identical to stat(), except that the file about which information is to be retrieved is specified by the file descriptor fd.

> On success, zero is returned.  On error, -1 is returned, and errno is set to indicate the error.

## unlink (sys)

delete a name and possibly the file it refers to.

https://man7.org/linux/man-pages/man2/unlinkat.2.html

- deletes  a  name  from the filesystem.  If that name was the last link to a file and no processes have the file open, the file is deleted and the
space it was using is made available for reuse.
- If the name was the last link to a file but any processes still have the file open, the file will remain in existence until the last file descriptor referring to it is closed.
- If the name referred to a symbolic link, the link is removed.
- If the name referred to a socket, FIFO, or device, the name for it is removed but processes which have the object open may continue to use it.

## execve (sys)

execute program

https://man7.org/linux/man-pages/man2/execve.2.html

## dup, dup2 (sys)

https://man7.org/linux/man-pages/man2/dup2.2.html

duplicate a file descriptor

## pipe (sys)

creates a pipe, a unidirectional data channel that can be used for interprocess communication.

https://man7.org/linux/man-pages/man2/pipe.2.html

## opendir

- opendir : https://man7.org/linux/man-pages/man3/opendir.3.html

- readdir : https://man7.org/linux/man-pages/man3/readdir.3.html

- closedir : https://man7.org/linux/man-pages/man3/closedir.3.html

- strerror : returns a pointer to a string that describes the error code passed in the argument errnum. https://man7.org/linux/man-pages/man3/strerror.3.html

- perror : print a system error message. https://man7.org/linux/man-pages/man3/perror.3.html

## TTY

isatty : https://man7.org/linux/man-pages/man3/isatty.3.html

ttyname : https://man7.org/linux/man-pages/man3/ttyname.3.html

ttyslot : https://man7.org/linux/man-pages/man3/ttyslot.3.html

ioctl (sys) : https://man7.org/linux/man-pages/man2/ioctl.2.html

getenv : get an environment variable https://man7.org/linux/man-pages/man3/getenv.3.html

## Termios (tcsetattr & tcgetattr)


Warning : there exists a manpage for the POSIX implementation. The correct man page for the Linux implementation is the following : https://man7.org/linux/man-pages/man3/termios.3.html


- tcsetattr

- tcgetattr

## Curses

https://linux.die.net/man/3/tgetent

tgetent

tgetflag

tgetnum

tgetstr

tgoto

tputs



# How it works

## Show me a prompt

The `readline()` function is great.

## History management

To add an entry to the history :

```C
add_history(input);
```
