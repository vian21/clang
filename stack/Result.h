#ifndef RESULT_H
#define RESULT_H

typedef struct
{
    unsigned short is_ok;
    union
    {
        void *value;
        char *error;
    };

} Result;

/* Returns an Result<Ok, NONE>*/
Result Ok(void *value);

/* Returns an Result<NONE, Err>*/
Result Err(char *error);

#endif