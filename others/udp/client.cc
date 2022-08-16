//https://www.prodevelopertutorial.com/linux-system-programming-creating-udp-sockets/
// 1. Create a socket using “socket()”
// 2. bind to an address using “bind()”
// 3. Send the data to server using “sendto()”
// 4. Receive the data from the server using “recvfrom()”
// 5. Close the connection using “close()”

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{

    int port = 1234;
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serverAddr, '\0', sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer, "Hello Server\n");
    sendto(sockfd, buffer, 1024, 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    printf("[+]Data Send: %s", buffer);

    return 0;
}