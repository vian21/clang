#define MAX_SIZE 100

/*
 * inserts a value onto the stack
 * return 1 success | 0 error 
*/
int push(int value);

/*
 * removes a value from the stack
*/
int pop(void);

/* returns boolean */
int is_empty(void);