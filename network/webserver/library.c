#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void close_exit(int socket)
{
    close(socket);
    exit(EXIT_FAILURE);
}

void format_response(char *response, char *body)
{
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", strlen(body), body);
}