#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

static void StackGroup(stack *);

void StackNew(stack *s, int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->size = 0;
    s->capacity = 4;
    s->elems = malloc(4 * elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s)
{
    free(s->elems);
}

void StackPush(stack *s, void *elemAddr)
{
    if(s->size == s->capacity)
        StackGroup(s);

    void *target = (char *)s->elems + s->size * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
}

void StackPop(stack *s, void *elemAddr)
{
    void *source = (char *)s->elems + (s->size - 1) * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
    s->size--;
}

static void StackGroup(stack *s)
{
    s->capacity *= 2;
    s->elems = realloc(s->elems, s->capacity);
    assert(s->elems != NULL);
}
