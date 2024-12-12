#include "main.h"

int main(int argc, char **argv)
{

    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof(struct addrinfo));
    (&hints)->ai_protocol=IPPROTO_UDP;
    (&hints)->ai_family=AF_INET;
    getaddrinfo(argv[1], NULL, &hints, &res);
    struct addrinfo *current = res;
    
    int fd=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    connect(fd,res,BUFFER);
    

}