#include "functions.h"
int buildRequest(char* buffer,int opcode,char* filename,char* mode){
    opcode=htons(opcode);
    int offset=0;
    memcpy(buffer + offset, &opcode, sizeof(opcode));
    offset += 2;

    // Copy the filename to the buffer
    strcpy(buffer + offset, filename);
    offset += strlen(filename)+1; // Include null terminator

    // Copy the mode to the buffer
    strcpy(buffer + offset, mode);
    offset += strlen(mode) +1; // Include null terminator

    // Return the total length of the packet
    return offset;
}