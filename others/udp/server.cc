//https://www.prodevelopertutorial.com/linux-system-programming-creating-udp-sockets/
// 1. Create a socket using “socket()”
// 2. bind to an address using “bind()”
// 3. Wait for the data to be received using “recvfrom()”
// 4. Send the data to client using “sendto()”
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
    struct sockaddr_in si_me, si_other;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&si_me, '\0', sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr *)&si_me, sizeof(si_me));
    addr_size = sizeof(si_other);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&si_other, &addr_size);
    printf("[+]Data Received: %s", buffer);

    return 0;
}