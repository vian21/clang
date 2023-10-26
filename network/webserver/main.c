#include "headers.h"
#include "library.h"

#define SERVER_PORT 5000

int main()
{
   int server_socket = new_webserver(SERVER_PORT);

    // accept connections
    struct sockaddr_in client_address;
    int client_socket;
    int address_len = sizeof(client_address);

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

        char response_buffer[1024];

        handle_request(request, response_buffer);

        (void)write(client_socket, response_buffer, strlen(response_buffer));

        (void)close(client_socket);
    }

    (void)close(server_socket);

    exit(EXIT_SUCCESS);
}