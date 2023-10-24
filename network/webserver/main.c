#include "headers.h"
#include "library.h"

#define SERVER_PORT 5000
#define REQUEST_LEN 1024

int main()
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
    server_address.sin_port = htons(SERVER_PORT);
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

    printf("Server started on port: %d\n", SERVER_PORT);

    // accept connections
    struct sockaddr_in client_address;
    int client_socket;
    int address_len = sizeof(client_address);
    int n_requests = 0;
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_len)))
    {
        // get client request
        char request[REQUEST_LEN];
        int request_size = read(client_socket, request, REQUEST_LEN);

        if (request_size < 0)
        {
            perror("Empty request");
            continue;
        }

        // tokenize
        char *tokens = strtok(request, " ");
        char *request_type = tokens;
        char *path = strtok(NULL, " ");

        printf("[LOG] Request %d %s %s\n", n_requests++, request_type, path);

        char *message = "Hello Browser\n";

        char response[1024];
        format_response(response, message);
        write(client_socket, response, strlen(response));

        (void)close(client_socket);
    }

    (void)close(server_socket);
    (void)close(client_socket);

    exit(EXIT_SUCCESS);
}