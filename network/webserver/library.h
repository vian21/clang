#ifndef LIBRARY_H
#define LIBRARY_H

void close_exit(int);

/* 
 * Format HTTP response by appending required headers
 *
 * HTTP/1.1 200 OK
 * Content-Length: strlen(body)
 */
void format_response(char *response, char *body);
#endif