#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

typedef enum {
    OP_RETURN,
} OpCode;

// bytecode is a series of instructions.
// we’ll store some other data along with the instructions
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void init_chunk(Chunk* chunk);
void write_chunk(Chunk* chunk, uint8_t byte);
void free_chunk(Chunk* chunk);

#endif

// each instruction has a one-byte operation code