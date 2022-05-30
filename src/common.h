#ifndef clox_common_h
#define clox_common_h

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "chunk.h"

#define DEBUG_PRINT_CODE
#define DEBUG_TRACE_EXECUTION

typedef enum
{
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
} ValueType;

typedef struct
{
    ValueType type;
    union
    {
        bool boolean;
        double number;
    } as;
} Value;

#endif