#include "Result.h"

Result Ok(void *value)
{
    return (Result){
        .is_ok = 1,
        .value = value
        };
}

Result Err(char *error)
{
    return (Result){
        .is_ok = 0,
        .error =  error};
}
