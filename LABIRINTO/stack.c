#include <stdlib.h>
#include "stack.h"
#include "maze.h"

STACK *stack_create() {
	return (STACK *) calloc(1, sizeof(STACK));
}

int stack_push(STACK *stack, int elem) {
	if (!stack) return INVALID_STACK;
	STACK_ELEMENT *e = (STACK_ELEMENT *) malloc(sizeof(STACK_ELEMENT));
	e->elem = elem;
	e->next = stack->top;
	stack->top = e;
	stack->counter++;

	return SUCCESS;
}

int stack_pop(STACK *stack) {
	if (!stack) return INVALID_STACK;

	if (!stack->counter) return EMPTY_STACK;

	STACK_ELEMENT *elem = stack->top;
	stack->top = elem->next;
	free(elem);
	stack->counter--;

	return SUCCESS;
}

int stack_top(STACK *stack) {
	if (!stack) return INVALID_STACK;

	if (!stack->counter) return EMPTY_STACK;
	
	return stack->top->elem;
}

int stack_size(STACK *stack) {
	if (!stack) return INVALID_STACK;
	return stack->counter;
}

int stack_free(STACK *stack) {
	if (!stack) return INVALID_STACK;
	int i;
	STACK_ELEMENT *e;
	for (i = 0; i < stack->counter; i++) {
		e = stack->top;
		stack->top = e->next;
		free(e);
	}
	free(stack);
	return SUCCESS;
}