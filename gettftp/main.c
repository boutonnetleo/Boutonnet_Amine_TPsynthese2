#include "main.h"

int main(int argc, char **argv)
{
    char* host_adrr=argv[1];
    char* host_port=argv[2];
    char* filename=argv[3];
    char* mode="octet";
    struct addrinfo hints;
    struct addrinfo *res;
    char buffer[TRAM_LENGTH]="%d%s%d%s%d";
    scanf(buffer,OP_READ,filename,0x0,mode,0x0);

    memset(&hints, 0, sizeof(struct addrinfo));
    (&hints)->ai_protocol=IPPROTO_UDP;
    (&hints)->ai_family=AF_INET;
    (&hints)->ai_socktype=SOCK_DGRAM;
    getaddrinfo(host_adrr, host_port, &hints, &res);
    struct addrinfo *current = res;
    printf("found something \n");
    printf("\t ai_family =%d\n", current->ai_family);
    printf("\t ai_socktype =%d\n", current->ai_socktype);
    printf("\t ai_protocol =%d\n", current->ai_protocol);

    int fd=socket(current->ai_family,current->ai_socktype,current->ai_protocol);
    connect(fd,(struct sockaddr*)res,TRAM_LENGTH);
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
   send(fd,buffer,TRAM_LENGTH,0);
    

}


