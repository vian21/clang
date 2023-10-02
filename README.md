# clang

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

- `%ld` - decimal long
- `%5ld` - decimal long of at least 5 characters wide

- `%o` - print an octal
- `%x` - print a hexadecimal

- `%f` - float point number
- `%5f` - float point number of at least 5 characters wide
- `%.2f` - float point number of 2 characters after the decimal point
- `%5.2f` - float point number of at 5 characters wide and 2 characters after the decimal point

- `%c` - print a character
- `%s` - print a character string

- `%%` - print the % sign

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

```c
struct Person{
  int age;
  char *name;
}
```

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
