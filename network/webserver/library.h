#ifndef LIBRARY_H
#define LIBRARY_H

#define REQUEST_LEN 1024

typedef enum HTTP_Verb
{
    GET,
    POST,
    PUT,
    DELETE
} HTTP_Verb;

typedef enum Status_code
{
    OK = 200,
    NOT_FOUND = 404,
    SERVER_ERROR = 503
} Status_code;

// Create a new webserver socket
int new_webserver(int port);

void close_exit(int);

/*
 * Format HTTP response by appending required headers
 *
 * HTTP/1.1 200 OK
 * Content-Length: strlen(body)
 */
void format_response(char *response_buffer, Status_code code, char *path, char *body);

/*
 * Handles raw HTTP request
 *
 */
void handle_request(char *request, char *response_buffer);

void error_page(Status_code code, char *response_buffer);
#endif