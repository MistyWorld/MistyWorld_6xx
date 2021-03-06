

#include <stdlib.h>
#include "DetourAlloc.h"

static void *dtAllocDefault(int size, dtAllocHint)
{
	return malloc(size);
}

static void dtFreeDefault(void *ptr)
{
	free(ptr);
}

static dtAllocFunc* sAllocFunc = dtAllocDefault;
static dtFreeFunc* sFreeFunc = dtFreeDefault;

void dtAllocSetCustom(dtAllocFunc *allocFunc, dtFreeFunc *freeFunc)
{
	sAllocFunc = allocFunc ? allocFunc : dtAllocDefault;
	sFreeFunc = freeFunc ? freeFunc : dtFreeDefault;
}

void* dtAlloc(int size, dtAllocHint hint)
{
	return sAllocFunc(size, hint);
}

void dtFree(void* ptr)
{
	if (ptr)
		sFreeFunc(ptr);
}
