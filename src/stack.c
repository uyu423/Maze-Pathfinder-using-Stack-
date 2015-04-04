#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void stackPush(stackManager *stackMgr, element item) {
	if (stackFull(stackMgr)) {
		stackMgr->stack = (element *)realloc(stackMgr->stack, (2 * (stackMgr->size) * sizeof(element)) + sizeof(element));
		stackMgr->size *= 2;
	}
	stackMgr->stack[++(stackMgr->top)] = item;
	return;
}

element stackPop(stackManager *stackMgr) {
	if (stackEmpty(stackMgr)) {
		printf("stack empty\n");
		return;
	}
	return stackMgr->stack[(stackMgr->top)--];
}

bool stackFull(stackManager *stackMgr) {
	if (stackMgr->top >= stackMgr->size) {
		return true;
	}
	return false;
}

bool stackEmpty(stackManager *stackMgr) {
	if (stackMgr->top < 0) {
		return true;
	}
	return false;
}

void makeStack(stackManager *stackMgr) {
	stackMgr->stack = (element *)malloc(2 * sizeof(element));
	stackMgr->size = 1;
	stackMgr->top = -1;
	return;
}
