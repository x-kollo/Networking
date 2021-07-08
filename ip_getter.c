#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    char ipv4_str[INET_ADDRSTRLEN];
    struct addrinfo hints, *info;

    memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; 
	hints.ai_socktype = SOCK_STREAM;
    int getaddr_error;
	if ((getaddr_error = getaddrinfo(argv[1], NULL, &hints, &info)) != 0) 
    {
		printf("getaddrinfo: %s\n", gai_strerror(getaddr_error));
		return -1;
	}
    struct sockaddr_in *ipv4 = (struct sockaddr_in*)info->ai_addr;
    printf("web-site %s \n", argv[1]);
    inet_ntop(info->ai_family, &(ipv4->sin_addr), ipv4_str, INET_ADDRSTRLEN);
    printf("IP: %s\n", ipv4_str);
    freeaddrinfo(info);
    return 0;
}