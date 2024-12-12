#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TRAM_LENGTH 512

#define OP_READ 0x01
#define OP_WRITE 0x02
