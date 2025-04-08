#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    socklen_t len = sizeof(server);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    printf("Client : ");
    fgets(buffer,BUFFER_SIZE,stdin);
    sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&server, len);
    printf("Message sent to server\n");

    memset(response, 0, BUFFER_SIZE);
    recvfrom(sockfd, response, BUFFER_SIZE, 0, (struct sockaddr *)&server, &len);
    printf("Message from server: %s\n", response);

    close(sockfd);
    return 0;
}
