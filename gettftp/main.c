#include "main.h"

int main(int argc, char **argv)
{
    char *host_adrr = argv[1];
    char *host_port = argv[2];
    char *filename = argv[3];
    char *mode = "octet";
    struct addrinfo hints;
    struct addrinfo *res;
    char buffer[TRAM_LENGTH];
    char buffer_receive[TRAM_LENGTH];
    size_t size = buildRequest(buffer, OP_READ, filename, mode);
    // print the buffer
    for (int i = 0; i < size; i++)
    {
        printf("%02X ", (unsigned)buffer[i]);
    }
    printf("\n");
    memset(&hints, 0, sizeof(struct addrinfo));
    (&hints)->ai_protocol = IPPROTO_UDP;
    (&hints)->ai_family = AF_INET;
    (&hints)->ai_socktype = SOCK_DGRAM;
    getaddrinfo(host_adrr, host_port, &hints, &res);
    /*
    struct addrinfo *current = res;
    printf("found something \n");
    printf("\t ai_family =%d\n", current->ai_family);
    printf("\t ai_socktype =%d\n", current->ai_socktype);
    printf("\t ai_protocol =%d\n", current->ai_protocol);
    */

    int fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    printf("%d\n", fd);
    sendto(fd, buffer, size, 0, res->ai_addr, res->ai_addrlen);
    /*
        2 bytes     string    1 byte     string   1 byte
        ------------------------------------------------
       | Opcode |  Filename  |   0  |    Mode    |   0  |
        ------------------------------------------------
            RRQ/WRQ packet

        2 bytes     2 bytes
        ---------------------
        | Opcode |   Block #  |
        ---------------------
            ACK packet

        2 bytes     2 bytes      n bytes
        ----------------------------------
        | Opcode |   Block #  |   Data     |
        ----------------------------------

            DATA packet

         opcode  operation
            1     Read request (RRQ)
            2     Write request (WRQ)
            3     Data (DATA)
            4     Acknowledgment (ACK)
            5     Error (ERROR)

        The mode field contains the
string "netascii", "octet", or "mail" --> on choisi octet
*/

    size_t sizereceive = recv(fd, buffer_receive, TRAM_LENGTH, 0);
    for (int i = 0; i < sizereceive; i++)
    {
        printf("%02X ", (unsigned)buffer_receive[i]);
    }
    printf("\n");
    char buffer_ack[TRAM_LENGTH];
    int size_ack = buildAck(buffer_ack, buffer_receive);
    sendto(fd, buffer_ack, size_ack, 0, res->ai_addr, res->ai_addrlen);
    close(fd);
    printf("fin \n");
}
