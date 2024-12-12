#include "main.h"

int main(int argc, char **argv)
{

    struct addrinfo hints;
    struct addrinfo *res;

    memset(&hints, 0, sizeof(struct addrinfo));

    getaddrinfo(argv[1], NULL, &hints, &res);
    struct addrinfo *current = res;
    while (current->ai_next != NULL)
    {
        printf("found something \n");
        printf("\t ai_family =%d\n", current->ai_family);
        printf("\t ai_socktype =%d\n", current->ai_socktype);
        printf("\t ai_protocol =%d\n", current->ai_protocol);
        current = current->ai_next;
    }
}