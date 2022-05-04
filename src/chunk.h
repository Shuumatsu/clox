#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    // OP_CONSTANT takes a single byte operand that specifies which constant to
    // load from the chunk’s constant array.
    OP_CONSTANT,
    OP_NEGATE,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_RETURN,
} OpCode;

// bytecode is a series of instructions.
// we’ll store some other data along with the instructions
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;

    ValueArray constants;

} Chunk;

void init_chunk(Chunk* chunk);

void write_chunk(Chunk* chunk, uint8_t byte, int line);

void free_chunk(Chunk* chunk);

// return the index of the newly added value
int add_constant(Chunk* chunk, Value value);

#endif

// each instruction has a one-byte operation code