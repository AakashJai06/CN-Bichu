#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server, client;
    char buffer[BUFFER_SIZE];
    socklen_t len = sizeof(client);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(sockfd, (const struct sockaddr *)&server, sizeof(server));
    printf("UDP Server is running and waiting for data on port %d...\n", PORT);

    memset(buffer, 0, BUFFER_SIZE);
    recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client, &len);
    printf("Message from client: %s", buffer);

    char response[] = "Hello from server";
    sendto(sockfd, response, strlen(response), 0, (struct sockaddr *)&client, len);
    printf("Response sent to client\n");

    close(sockfd);
    return 0;
}
