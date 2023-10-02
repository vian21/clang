#ifndef RESULT_H
#define RESULT_H

typedef struct Result
{
    int is_ok;
    int value;
    char *error;

} Result;

static inline Result Ok(int value)
{
    return (Result){
        .is_ok = 1,
        .value = value,
        .error = "None"};
}

static inline Result Err(char *error)
{
    return (Result){
        .is_ok = 0,
        .value = 0,
        .error = error};
}

#endif