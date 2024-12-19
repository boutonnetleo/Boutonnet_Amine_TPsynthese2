#include <string.h>

#define OP_ACK 04
#define OP_DATA 03
#define BlockSize 2
int buildRequest(char* buffer,int opcode,char* filename,char* mode);
int buildAck(char* buffer,char* data);
void getBlock(int* block,char* buffer_received);