#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"
#define TRAM_LENGTH 512

#define OP_READ 01
#define OP_WRITE 02
int buildRequest(char* buffer,int opcode,char* filename,char* mode);