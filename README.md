_This project has been created as part of the 42 curriculum by kkweon_

## Description

**Goal** of get_next_line project is to create a function that reads a file and returns a line of text at a time.\
Each call to the function should return the next line from the file.\
**Purpose** of this project is to let us understand how files can be opened, closed, and managed using file descriptor (or fd), as well as how static variables can be used to preserve data between function calls.

#### File descriptor (fd)
> File descriptor (or fd) is an index variable which is assigned to identify an open file.\
fd typically uses a unique, non-negative integer for assigning an open file.

#### File Table Entry
> It is a structure which is maintained from Kernerl side, contains information about the assgined file.

#### File Descriptor Table
> An array of File Table  Entry which stores references (fd) to the opened files. Each File Table Entry holds a pointer links the fd to the **Global File Descriptor**

#### Static variables
> Property of static variable is to retaining the value between multiple function calls.\
Once it is initialized, the value is stored and does not get destroyed when the function ends, but stores the value until when the program ends. 
#### Example
```C
#include "stdio.h"

int not_static_var()
{
    int num = 0;
    num++;
    return (num);
}

int static_var()
{
    static int num = 0;
    num++;
    return (num);
}

int main (void)
{
    printf("%d\n", not_static_var());
    printf("%d\n", not_static_var());
    printf("%d\n", static_var());
    printf("%d\n", static_var());
    return (0);
}
```
#### Results:
```bash
regular int: 1
regular int: 1
static int: 1
static int: 2
```

## Instructions

This program or function is written in C and requires a C compiler such as **gcc** or **cc**.\
> <ins> In order to run the program, we need a txt file to run the program on first.</ins>
1. To use get_next_line, following header file is required:

```C
#include "get_next_line.h"
```

2. To compile, use a C compiler and define the BUFFER_SIZE macro.  
If BUFFER_SIZE is not declared it will automatically declare the BUFFER_SIZE as 10.

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## Resources

- `man open`
- `man read`
- `man close`
- [Static Variable in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [42 gitbook get_next_line](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line)
- [42 Get Next Line Guide (String Approach) — Chapter 1: Reading from file](https://medium.com/@lannur-s/gnl-c3cff1ee552b)

**LLMs (e.g., ChatGPT, Gemini, Claude)** were not used to for direct code generation.\
AI is used as supportive tools to understand concepts, programming logic, and to enhance learning efficiency.