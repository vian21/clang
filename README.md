# clang

# Manpages

- Section 1 of the man pages covers `command-line tools`
- section 2 covers `system calls`
- section 3 covers `user-space libraries`

### Headers

- Headers define code to be included from other files
- They can be included from two locations
  - C implimentation headers i.e `/usr/include/` e.g `#include <stdlib.h>`
  - from the current folder e.g `#include "functions.h"`

### Return codes (main)

- 0 - return with no error
- Anything else - return with error
- Default return type -> `int`

## Data types

- When declaring a variable you can either initialize it or not
- If you dont initialize a variable the variable will contain arbitrary values that were contained in the memory cell it was assigned to by the program.

- Primitives:
  - int (4 bytes)
  - float (4 bytes)
  - double (8 bytes)
  - char (1 byte)
- Arrays:

```c
int list[10] =[];
```

- Intergers can be :
  - long (8 bytes) `long int a = 1; | long a = 1;`
  - short (2 bytes)
  - signed
  - unsigned
- char can also be `signed` or `unsigned`
- doubles can only `long` not short

## variables

- most variables are localized in the function they are declared in. These are known as `automatic variables`.
- TO be able to use global variables variables in C. Declare them at the top of the program and exactly once
- any where the variable should be used, use the extern keyword to implicitly state that the variable bein used is the global variable AKA `external variables` though it is not required
- Variable definition: where the varaible is created or assigned storage
- declaration: where the nature/type is stated without allocating space for it.

## initialisation

- most primitive data types will contain garbage values when declared and not initialised
- that includes:
  - int
  - arrays
- `char`s will be undefined and wont containt any value at declaration

## Pre-processor directives

- Statements that tell the compiler what code to inject at compile time
- the compile is going to replace where those directives are and replace them with their actual value
- For example, if it is constant like PI, you can declare a macro, and when it is time to compile, the compiler is going to take wherever you used your macro and replace with the actual value. No variable is declared or memory used.
- Preprocessors directives include:
  - include
  - define
  - ifdef

## printf()

### Escape/special characters

- `\n` - new line character
- `\t` - horizontal tab
- `\v` - vertical tab
- `\b` - backspace. Remove one character
- `\a` - alert bell sound

### Variable substitution

- `%d` - decimal integer
- `%5d` - decimal integer of at least 5 characters wide
- `u` - unsigned int

- `%ld` - decimal long
- `%5ld` - decimal long of at least 5 characters wide

- `%o` - print an octal
- `%x` | `%X` - print a hexadecimal

- `%f` - float point number
- `%5f` - float point number of at least 5 characters wide
- `%.2f` - float point number of 2 characters after the decimal point
- `%5.2f` - float point number of at 5 characters wide and 2 characters after the decimal point

- `E | e` - print double using standard form
- `f` - print double using default precision (6)

- `%c` - print a single character
- `%s` - print a character string

- `%%` - print the % sign

- `%p` - print address of void pointer in hex

### Getting input and output

- A character is stored as numerical literal in memory, which means a character can both be used as an int or char
- getchar(char c) - gets a character from the std input
- putchar(char c) - prints one character to the std output
- fputc(char c) writes the character c, cast to an unsigned char, to stream.
- fputs(char c) writes the string s to stream, without its terminating null byte ('\0').
- putc(char c) is equivalent to fputc() except that it may be implemented as a macro which evaluates stream more than  
  once.
- putchar(char c) is equivalent to putc(c, stdout).
- puts(char\* c) writes the string s and a trailing newline to stdout.

### Symbolic constants

- `#define name replacement`
- every occurence of name will be replaced with the replacement string of characters
- used to avoid magic values
- `name` - should follow variable naming conventions
- `replacement` - can be a string, number, ...

```c
#define a 10  //int. If value is too big for an int. it will be set to a long
#define a 10l //long
#define a 10L //long
#define a 10.0  //double
#define a 1e1   //double
#define a 1e1L   //long double
#define a 10.0f //float
#define a 10.0F //float

#define a 010 //octal
#define a 0x10 //hexadecimal

#define VTAB '\013'  //character constant using octals
#define VTAB '\xb'   //char using hex
#define VTAB '\013'

#define string "hello, world"
#define string "hello," "world"  //will be concatanated at runtime

enum Gender {MALE, FEMALE}; //enum. Male will have value 0 and female 1
enum Months {JAN=1, FEB, MARCH};  //will continue the progression
enum Escapes {BELL='\a', BACKSPACE='\b'}; //you can specify the value for each option
//use: access the enum value by the option name. No need to prefix the enum group. E.g MALE instead of Gender.Male
//enums are alternatives to using define statements. Give you the convenience of having the values generated for you instead of hard coding them using define statements.
```

## Macro substitution

- having expression being represented by a symbolic name

```c
#define max(A,B) ((A)>(B))? (A) : (B)
max(i++, j++);
//the above would be evaluated twice and would have the side effect of having each variable incremented twice. One when passed, second when the expression is evaluated
```

- care has to be taken with parenthesis to preserve the order of operation

```c
#define square(x) x*x

```

```c
#if !define(HEADER_H)
#ifndef HEADER_H
#endif
#ifdef LINUX

#if SYSTEM==LINUX
#elif SYSTEM==WIN
#endif
```

- the `#ifndef` is only used to prevent including the file multiple times in the same program. It does not guarantee the it was not included in another c file.
- each time you include a file, its contents is copied into the current file.
- Including a header file in multiple files means that it will be copied multiple time. If the headre file contains fucntion definitions, these definitions will class. but declarations dont.
- You can includ the function definition by making the function `static inline` i.e the function will be copied to the file where it is used and will be scoped to that file only hence removing clashes
- one downside is it make the program bigger since the function is define multiple time(extra code)

### Conditionals

- and -> `&&`
- or -> `||`

```c
if(a == 10)
  return 10;  //no need for curly brackets for a single expresssion and doesnt care about indentation
else if(a == 15)
  return 15
else if(a == 100)
  return 100;
else
  return 0
```

### Ternary condition

```c
int sign = (number[i] == '-')? -1 : 1;
```

## Arrays

### int

```c
int a[10];
int a[3] = {0,1,2};
char a[2];
```

## Functions

- function declarations can appear in any order. i.e you can define the function declaration at the beginning of the program without implementing it. YOu can later implement it at the bottom

- C uses pass by value by default. A copy of your variable will be passed to the function not a reference

- `sizeof`(int | char | float | type) -> long of number of bits
- `strlen`(char \*) -> returns the number of char in a string including the `\0`

## Qualifiers

### const

- indicates that the value of a variable will not be changed
- function parameter pointer will not be changed

```c
const int a = 10;
int strlen(const char s[]){}
```

## Arithmtic

- C will auto-cast when casting from a smaller size type to higher
- Rules of auto-cast

1. If either operand is long double, cast the other to long double
2. Otherwise, if either operand is double, cast the other to double
3. Otherwise, if either operand is float, cast the oher to float
4. Otherwise, convert char and short to int
5. Then, if either operand is long, convert the other to long

## Casting

#### Explicit type coercion

```c
(type) expresion
double sqrt((double) n);
printf("%f", (int)1.3333);

```

### increment operator

- n++

  - increments the value after it has been used

- ++n

  - increment value before use

  ```c
  int n= 5;
  int x = n++;
  //sets x to 5 and then increments n. x will keep the value of 5. and n will be incremented

  int x = ++n;
  //increments n and then sets x to the incremented value

  ```

## Bitwise operators

- C provides 6 operators to carry out bit manipulation that can be applied on int, char, short, long
  - & bitwise AND
  - | inclusive OR
  - ^ exclusive OR
  - << left shift
  - > > right shift
  - ~ one's compliment

1. Bitwise AND &

- ANDs every bit in each expresssion. E.g:
  - 111 & 110 -> 110
  - 11111 & 10 -> 10
- Truncates any excess bits

2. Bitwise OR |

- ORs every bit
  - 111 | 110 -> 111
  - 111 OR 101: 111
  - 1111 OR 111: 1111
  - 111 OR 1111: 1111
- keeps any excess bits

3. Exclusive OR (XOR) ^
   | a | b | output |
   | -- | -- | -- |
   | 0 | 0 | 1 |
   | 0 | 1 | 1 |
   | 1 | 0 | 1 |
   | 1 | 1 | 0 |

- Like OR, keeps excess bits but gives 0 when boths bits are 1's

3. Left shift

- ## Multiplies by 2^n

4. Right shift

- divides by 2^n

# Blocks

### Switches

```c
switch(expression){
  case const-expr: statement
  case const-expr: statement
  case const-expr: statement
  default: statement
}
```

- each case is evaluated top to bottom. If one case if one expression is evaluated true, yhe statements defined will be executed and all the following statements unless a break statement or returnis encountered.
- each case expression must be an integer expression not a condition.

## Goto and Labels

- It is best practice not to use goto statements in your code to avoid creating spaghetti code that is really hard to navigate and map
- Gotos are primarily used when you want to go a certain state when you are deep in a deeply nested structure
- They allow you to handle situation where just break or return will only stop one layer of processing

```c
while(){
  while(){
    while(){
      goto error;
    }
  }
}

error:
  //clean up
```

## Static variables

- static variables are variables that are only available to function inside the file they are declared in.
- denoted by the `static` keyword
- This enables these variable names to be scoped and not conflict with other variables in other files
- can also be used with functions

```c
static int stack[MAX];
static void delete_node(Node *n);
```

## header files

- used to declare function or variables that will be available in the program. These can eitherr be implemented inside the program itself or dependencies.
- contains function return type and parameter types
- Contains function declaration or implementations themselves
- if header contains implementation no need to add it when compiling it the code will automatically be added to the main file
- when implementations of said functions is in `.c` file that file has to be included when compiling

```sh
cc main.c stack.c other.c
```

- function can have multiple declarations but only one declaration
- Parameter declarations dont need to have names

```c
int square(int);
int add(int, int);
```

# Pointers and Arrays

- A pointer is a variable that contains the address of a variable
- `&` - used to get the address of an object
- `*` - used to deference a pointer and refer to the actually object being pointed to
- Pointer addition is illegal but pointer subtraction is legal

```c
int *ip;
int x = 10;
*ip = &x; //ip points to x
int y = *ip; //y is equal to the value of x == *ip
```

```c
*ip +=10;
*ip +=1;
y = *ip +1 ; //takes what ip points to, adds 1 and assigns it to y
++*ip; //increments the value being pointed to
(*ip)++; //parathensis needed because




```

## Struct

- used to create a data structure i.e contiguous(consecutive) cells of memory bigger than the primitive sizes
- comprised of a struct declaration `struct` and tag name
- variables in a struct are called `members`

```c
struc tagName{
  int member1;
  char member2;
}

```

```c
struct Person{
  int age;
  char *name;
}

struc Person person = {10, "John"};
struc Person person = {.age=10, .name="John"}

```

- when struct declaration is followed by names, this will declare those as variables and set aside space for them
- if not the struct declaration will only be template and no memory will be set aside

```c
struct vector2{int x,y;} root,vertex;

root.x;
root.y;
```

- The only legal operations on a struct are copying it or assign it to a unit
- they may be returned from a function
- they can be referenced by `&`
- passed by value. A copy is made when passed to a function
- It is illegal for a structure to contain an instance of itself. But it can contain a pointer to a member of its type
- Pointers to structures are frequently used that there exist a shorthand

```c
struct Person person, *pp;

pp = &person;

printf("%s\n", (*pp).name);
printf("%s\n", pp->name);

```

- if `pp` is pointer to a struct, then members of the struct can be accessed using `->`

```c
struct{
  int len;
  char *strl;
}*p;

++p->len; //increments len not p
(++p)->len; //increments p
p++->len; //access p->len and then increments p after
```

#### WHere are strings stored in C?

- string literals are stored in the `data segment` of the program and are read only values

```c
char *s = "hello\0"; //can modify this string. Immutable
char s[5] = "hello"; //this can be modified
```

## Command line arguments

- `int argc` - argument count. The number of arguments passed to the program
  - 0 is always the index command used to execute the program
  - has n arguments + 1
- `char *argv[]` (argument vector) - an array of character pointers to program arguments
  - has always an extra value that contains a null pointer

## Pointers to function

why?

- assign it in array
- return a function from another function
- pass it to a function

```c
int (*func) (int, int);
void (*func) (void*, void*);

int *f(); //function that returns a pointer to an int
int (*f)(void); //pointer to a function that returns an int

int (*pf)(); //pointer to a function that returns an int
```

- any pointer can be cast to a void pointer and vice versa without any data loss

## Typedef

- used to declare an alias/alternative name for an existing type/struct

```c
typedef existingType aliasName;
typedef int Number;
typedef unsigned int Number;
```

- can also be used to alias a struct

```c
struct Person{
  int age;
  char *name;
};

typedef struct Person Person;
            (type)    (alias)
```

```c
//declares PersonPtr to be a pointer to a person struct
typedef  struct Person *PersonPtr

PersonPtr newPerson(void); //returns a person pointer. No need for *
```

## Compound literals

- used to construct unnamed objects

```c
int *p = (arr[2]){1,2};

struct Object *op = &(struct Object);

Result Ok(int value)
{
    return (Result) {
        .is_ok = 1,
        .value = value,
        .error = "None"
    };
}
```

## Unions

- unions are used to create structures with mutually exclusive attributes. (when on is defined the other we dont care)

```c
union User{
  int id;
  int groupId;
}
```

- The union variables will share the same memory space. The struct will be the length of the biggest attributes plus compiler defined padding

- union in a struct can either be named or anonymous

```c
struct operator {
    int type;
    union {
      int intNum;
      float floatNum;
      double doubleNum;
    } types;
};

operator op;
op.types.intNum = 10;

```

- when declared anonymously, the union variables will be accessible directly

```c
struct operator {
    int type;
    union {
      int intNum;
      float floatNum;
      double doubleNum;
    };
};

operator op;
op.intNum = 10;
```

## compiler options

- `Always compile your program with all warnings enabled`. NASA
- `-Wall`: Enable every warning
- `-Werror`: Convert warnings into errors
- `-Wunused`: This flag enables warnings for unused variables, functions, and parameters.
- `-Wformat`: It checks the arguments used in format strings for functions like printf and scanf to ensure they match the format string.
- `-Wpedantic`: It issues warnings for code that doesn't adhere to the C standard strictly.

```sh
gcc -Wall -Wextra -Werror -Wpedantic
```

## Make

```makefile
hey: one two
	# Outputs "hey", since this is the target name
	echo $@

	# Outputs all prerequisites newer than the target
	echo $?

	# Outputs all prerequisites
	echo $^

	touch hey

one:
	touch one

two:
	touch two

clean:
	rm -f hey one two
```

## Bit-fields

- used to declare a filed to contain one bit.
- This simplifies the fact of having the need to do bitwise operations on numbers to get values

```c
struct {
  unsigned in is_on: 1;
  unsigned int power_mode:1;
}
```

- This are used when you constrained in memory and need values to share the same byte word and not waste storage

## Input & Output

- C does not handle input and output
- We have to used the standard library
- `getchar`: gets the next character from the standard input. You need to test for `EOF` character

- In linux, peripherals are represented as file. Everything is a file
- When a program is executed by your shell. Three file descriptors are open:
  1. std input: 0
  2. std output: 1
  3. std error: 2
- `File descriptor`: int value that describes while file is open

- C provides `two functions`(sys calls) to read and write data from the std input and output.

```c
int read_data = read(int fd, char* buf, int n_bytes);
int write_data = write(int fd, char* buf, int n_bytes)

```

- `fd`: file descriptor
- `char * buf`: buffer to be written to or to read from
- `n_bytes`: the number of bytes to be transfered

### Variable length argument list

```c
void minprintf(char* fmt, ...);
```

- `...` mean that the functions can take a varying number of parameters and types
- it can only appear at the end of the function argumenet list

- To step throught the argument list, use the `stdarg.h` library

```c
void minprintf(char* fmt, ...){
  va_list ap;

  va_start(ap, fmt); //initialize ap as an argument list pointer after fmt variable.

}
```

- `ap`: argument pointer. Points to the first unamed argument

```c
va_arg(ap, int); //each call return the argument and steps ap to the next argument
```

- when done

```c
va_end(ap); ///clean up
```

## Scanf - Formatted input

- returns the number os successful matched and assigned input items

```c
int scanf(char* fmt, ...);
```

- each input argument must be a pointer because scanf will try to write to them following the fmt string

### sscanf

- reads from a string not std input

```c
int sscanf(char* string, char *fmt, ....);
```

#### fmt argumentss

- same as printf
- `%f` - only indicates that the value is a float but not a double
- To indicate the next argument is a double/long(8 bytes) use `l`(ell) before the format character i.e `%lf`
- cant `scanf` with `char*`, you have to allocate memory for your string.
- Either use `malloc` or `char []`
- tabs, carriage return and special char are ignored

- DISCLAIMER: Scanf can be overflowed when getting user input

### fopen

```c
FILE fp;
File fopen(char* name, char* mode)
```

- fopen will return NULL if there is an error
- Good to close the file after use since most OS limit how many files can be open at the same time

```c
int fclose(FILE *fp);
```

## Error handling - stderr & exit

- `exit(int code)`
  - `0` : sucessfully
  - `!=0`: with error
- output to `stderr` will not be piped to a file if stdout is being redirected. It will only be shown on the screen and not be piped

```c
fprintf(FILE *fd, char *fmt, ... );
fprintf(stderr, "Error occured in %s", filename);
```

## Line input & Output

- `gets(char *s)` - NEVER USE. Does not check for buffer overflows
- `puts(char *s)` - writes the string s and a trailing newline to stdout.
- `fgets(char *s, int length, FILE *fp)`
  - write length-1 chars from s to a file including
  - Reading stops after an EOF or a newline. If a newline is reead, it is stored into the buffer. A terminating null byte (`\0`) is stored after the last character in the buffer.
- `fputs(char *s, FILE *fp)` - writes the string s to stream, without its terminating null byte (`\0`)

# Unix file system

- In UNix/Linux, everything is a file i.e directories, devices

- A directory: files that contains a list of filenames and where they are located
- `inode`: is a file where all information about a file except its name is kept
- A directory entry consists of a `filename` and `inode number`
- Each open file is given a file descriptor. When you open a file, the kernel keeps track of all the opened files in `open files` entry table. It is an ID for that file for other process to stream it.

## Malloc

- malloc is used to request more heap memory
- Each program is given a given amount of heap memory when executed
- Memory blocks managed by malloc do not have to be contiguous. Each block contains:
  - pointer to next block
  - its size
  - empty slot: pointer to this block is returned
- malloc keeps track of these blocks in a free list(`circular linked list`). Each time it is caalled, it looks up in the free list and returns pointer to memory block being ceded. The memory block is removed from the free list
- Malloc calls `morecore(nbytes)` which calls `sbrk(nbytes)` which is used request the memory from the OS
- malloc is used to prevent calling `morecore` or `sbrk` everytime the program needs more memory. Requesting for memory is an expensive operation. Malloc helps by having a free list and uses already allocated memory.

# Socket Programming

Source: https://www.scaler.com/topics/socket-programming-in-c/

- Socket programming allows nodes/process to talk to each other using sockets/file
- Sockets are just files that are written to or read by two nodes that are in communication
<center>
<img src="https://scaler.com/topics/images/socket-programming.webp">
</center>

## Server

- A server program goes through the following stages:

### 1. Create socket

```c
int socket(int domain, int type, int protocol);
```

- `domain` represents the Address Family over which the communication will take place.
  - `AF_LOCAL/AF_UNIX`: on the same computer. Interprocess
  - `AF_INET/AF_INET6`: over internet domain
  - `AF_BLUETOOTH`: using low-level bluetooth connection
- `type`: type of connecition used in the socket
  - `SOCK_STREAM`: using tcp stream. More reliable
  - `SOCK_DGRAM`: using UDP packets
- `protocol`:represents the protocol used in the socket. This is represented by a number. When there is only one protocol in the protocol family, the protocol number will be 0, or else the specific number for the protocol has to be specified.
- returns a `socket descriptor`

### 2. Set socket options

```c
int setsockopt(int socket_descriptor, int level, int option_name, const void *value_of_option, socklen_t option_length);

if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &(1), sizeof(int))) {
    perror("Couldn't set options");
    exit(EXIT_FAILURE);
}

```

- The level parameter can take the following values:

- `SOL_SOCKET`: This is used for options that apply to the socket itself, such as SO_REUSEADDR or SO_KEEPALIVE.
- `IPPROTO_TCP` or `IPPROTO_UDP`: These are used for options that apply to the TCP or UDP protocols, respectively.
- `IPPROTO_IP`: This is used for options that apply to the IP protocol.

### 3. Bind socket to port

```c
int bind(int socket_descriptor , const struct sockaddr *address, socklen_t length_of_address);

/* example */
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(SERVER_PORT);
server_address.sin_addr.s_addr = INADDR_ANY;/* Address to accept any incoming messages.  */

if (bind(socketd, (struct sockaddr *)&server_address, sizeof(server_address)))
{
    perror("Failed to bind address");
}
```

### 4. Listen for incoming connections

```c
  int listen(int socket_descriptor, int back_log);
```

### 5. Accept/Handle incoming connection

```c
int accept(int socket_descriptor, struct sockaddr *restrict address, socklen_t *restrict length_of_address);
```

- Client goes through:

### 1. Create socket

### 2. Connect to server

```c
int connect(int socket_descriptor, const struct sockaddr *address, socklen_t length_of_address);
```

### 3. Write/read data

```c
// send message to the server
ssize_t write(int __fd, const void *__buf, size_t __n);
write(socket_descriptor, message, strlen(message));


// receive a message from the server
ssize_t read(int __fd, void *__buf, size_t __nbytes)
read(socket_descriptor, recieve_buffer, 100);

//->returns the number of bytes read or written to socket
```

# Multi-threading

- `Critical section`: code that is run concurrently by multiple threads which access the same resources
- The critical section must be executed as an `atomic operation`. only one thread can access the resource at time t.

## pthreads - POSIX threads

- ISO standrad to creat threads

### phread_create()

- create a thread assign it work

```c
int pthread_create(pthread_t *thread,
                          const pthread_attr_t * attr,
                          void *(*start_routine)(void *),
                          void *arg);
```

```c
pthread_t thread;

pthread_create(&thread, NULL, execute_work, &args )

void *execute_work(void *args){
  ...
  return NULL;
}
```

- `int pthread_join(pthread_t thread, void **retval)`: wait until thread is done
- `int pthread_mutex_lock(pthread_mutex_t *mutex)`: The mutex object referenced by mutex shall be locked by a call to pthread_mutex_lock() that returns zero or [EOWNERDEAD]. If the mutex is already locked by another thread, the calling thread shall block until the mutex becomes available.

## Semaphores
Source: https://en.wikipedia.org/wiki/Semaphore_(programming)
- A semaphore is a variable that is shared by all threads and is used to solve the crtical section proble. It is used for process synchronization
- Has 2 operations
  1. `wait(P)`: decrement semaphore
  2. `signal(V)`: increment semaphore to indicate availability
- Semaphores are used to keep track of how many users can access a resource at the same time(login analogy) or if a resource is available or not
- Most used algorithm is `pass the baton` where after a resource is done and signal(V), it calls up th next thread
- Most OS provide primitives to create semaphores and avoid threads reading the value of the semaphore multiple times.