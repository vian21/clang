#include "library.h"
#include "headers.h"
#include "time.h"

char not_found_error[] = "<p>Page not found</p>\n";
char server_error[] = "<p>Internal server error</p>\n";

int new_webserver(int port)
{
    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int true = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (void *)&true, sizeof(true)) < 0)
    {
        perror("Couldn't set server options");
        exit(EXIT_FAILURE);
    }

    // bind socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY; /* Address to accept any incoming messages.  */

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)))
    {
        perror("Failed to bind address");
        exit(EXIT_FAILURE);
    }
    // listen
    if (listen(server_socket, 10) < 0)
    {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port: %d\n", port);

    return server_socket;
}
void close_exit(int socket)
{
    close(socket);
    exit(EXIT_FAILURE);
}

void format_response(char *response_buffer, Status_code code, char *path, char *body)
{
    sprintf(response_buffer, "HTTP/1.1 %d \r\nContent-Length: %ld \r\n\r\n%s", code, strlen(body), body);
}

char *read_page(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    fseek(file, 0L, SEEK_END);
    long numbytes = ftell(file);
    fseek(file, 0L, SEEK_SET);

    char *text = (char *)calloc(numbytes, sizeof(char));

    fread(text, sizeof(char), numbytes, file);
    fclose(file);

    return text;
}
char *get_page(char *path)
{

    if (strcmp("/", path) == 0)
    {
        return read_page("www/index.html");
    }

    return NULL;
}

char *get_time()
{
    time_t now = time(NULL);
    struct tm tm_now;
    char* buff = malloc(100);

    localtime_r(&now, &tm_now);
    strftime(buff, sizeof(buff), "%c", &tm_now);

    return buff;
}

void handle_request(char *request, char *response_buffer)
{
    // tokenize
    char *tokens = strtok(request, " ");
    char *request_type = tokens;
    char *path = strtok(NULL, " ");

    (void)request_type;

    char * time = get_time();
    (void)printf("[LOG] %s %s \n", time, path);

    char *body = get_page(path);

    if (body == NULL)
    {
        error_page(NOT_FOUND, response_buffer);
        return;
    }

    format_response(response_buffer, OK, path, body);

    free(body);
}

void error_page(Status_code code, char *response_buffer)
{
    switch (code)
    {
    case NOT_FOUND:
        format_response(response_buffer, code, "", not_found_error);
        break;

    case SERVER_ERROR:
        format_response(response_buffer, code, "", server_error);
        break;
    default:
        break;
    }
}
