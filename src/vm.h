#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "memory.h"
#include "value.h"
#include "object.h"
#include "table.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    uint8_t* ip;

    Value stack[STACK_MAX];
    // points at the array element just past the element containing the top
    // value on the stack
    Value* stack_top;
    Table strings;
    Obj* objects;
} VM;

extern VM vm;

void init_vm();
void free_vm();

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

// InterpretResult interpret(Chunk* chunk);
InterpretResult interpret(const char* source);

void push(Value value);

Value pop();

#endif
