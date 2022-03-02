#include <stdio.h>
#include <stdlib.h>
// Data structure to represent a stack
typedef struct Stack
{
    int size;
    float data;
	struct Stack *next;
} Stack;
 
//Utility function to check if the stack is empty or not
int isEmpty(Stack *pStack) {
    return pStack == NULL;
}
// Utility function to return the size of the stack
int size(Stack *pStack) {
	return isEmpty(pStack)?0:pStack->size;
}
 
//Non applicable in a linked list implementation
// Utility function to check if the stack is full or not
/*int isFull(Stack *pStack) {
    return pStack->top == pStack->maxsize - 1;
}
*/ 
// Utility function to add an element `x` to the stack
int push(Stack **ptrpStack, float x)
{
    // If the stack has no elements
    if (*ptrpStack == NULL)
    {
		*ptrpStack = (Stack*)malloc(sizeof(Stack));
		printf("inserting new value %f\n", x);
		(*ptrpStack)->data = x;
		(*ptrpStack)->size = 1;
		(*ptrpStack)->next = NULL;
		return 0;
    }
	Stack *newStack = (Stack*)malloc(sizeof(Stack));
    printf("Inserting %f\n", x);
	//set the new stack to length of previous stack +1
	newStack->size = (*ptrpStack)->size+1; 
	(*ptrpStack)->size = 0;
	newStack->data = x;
	newStack->next = *ptrpStack;
	*ptrpStack = newStack;
    return 0;
}
 
// Utility function to pop a top element from the stack
int pop(Stack **ptrpStack, float* x)
{
    // check for stack underflow
    if (isEmpty(*ptrpStack))
    {
        printf("Stack Empty!\n");
        return -1;
    }
	Stack *newStack;
	newStack = *ptrpStack;
	float n = newStack->data;
	printf("Removing the value %f\n", n);
	*x = n;
	if((*ptrpStack)->next != NULL){
		(*ptrpStack)->next->size = newStack->size-1;
	}
	else{
		(*ptrpStack)->size = newStack->size-1;
	}
	*ptrpStack = (*ptrpStack)->next;
	free(newStack);
    // remove element decrement stack size by 1
    return 0;
}
 
// Utility function to peek at top element from the stack
int peek(Stack *pStack, float* x)
{
    // check for stack underflow
    if (isEmpty(pStack))
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    // return top of stack value
    *x = pStack->data;
    return 0;
}
 
int main()
{
    // create a stack of capacity 5
    Stack *pt = NULL;
    float  value;
 
    push(&pt, 1.0);
    push(&pt, 2.0);
    push(&pt, 3.0);
 
    printf("The stack size is %d\n", size(pt));
    peek(pt, &value);
    printf("Top val on stack is %f\n", value);
    pop(&pt, &value);
    pop(&pt, &value);
    pop(&pt, &value);
 
    if (isEmpty(pt)) {
        printf("The stack is empty\n");
    }
    else {
        printf("The stack is not empty\n");
    }
 
    return 0;
}