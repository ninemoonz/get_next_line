_This project has been created as part of the 42 curriculum by kkweon_

## Description

Goal of get_next_line project is to create a function that reads a file and returns a line of text at a time.
Each call to the function should return the next line from the file.
Purpose of this project is to let us understand how files can be opened, closed, and managed using file descriptor (or fd), as well as how static variables can be used to preserve data between function calls.

## Instructions

This program or function is written in C and requires a C compiler such as gcc or cc.

1. To use get_next_line, following header file is required:

```C
#include "get_next_line.h"
```

2. To compile, use a C compiler and define the BUFFER_SIZE macro. If BUFFER_SIZE is not declared it will automatically declare the BUFFER_SIZE as 42.

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## Resources

`man open`, `man read`, `man close`
[42 gitbook](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)
[get next line article](https://medium.com/@lannur-s/gnl-c3cff1ee552b)