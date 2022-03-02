#include <stdio.h>
#include <stdlib.h>
// Data structure to represent a queue
typedef struct Node{
	float data;
	struct Node* next;
}Node;
typedef struct Queue
{
    int size;
    Node* front;
    Node* rear;
} Queue;
 
// Utility function to initialize the queue
Queue* newQueue(void)
{
    Queue *pQueue = (Queue*)malloc(sizeof(Queue));
    pQueue->size = 0;
    pQueue->front = NULL;
    pQueue->rear  = NULL;
 
    return pQueue;
}
 
// Utility function to return the size of the queue
int size(Queue *pQueue) {
    return pQueue->size;
}
 
// Utility function to check if the queue is empty or not
int isEmpty(Queue *pQueue) {
    return (pQueue->size == 0);       
}
 
// Utility function to check if the queue is full or not
//isFull is not needed as the linked list is nynamically allocated, so there is no max size
/*int isFull(Queue *pQueue) {
    return (pQueue->size == pQueue->maxsize);  
}*/
 
// Utility function to add an element `x` to the queue
int insert(Queue *pQueue, float x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = NULL;
    // check if the queue is already full
	printf("Inserting %f\n", x);
    if (isEmpty(pQueue))
    {
        pQueue->front = pQueue->rear = temp;
    }
	else{
		pQueue->rear->next = temp;
		pQueue->rear = temp;
	}
	pQueue->size++;
    
    return 0;
}
 
// Utility function to remove an element from the queue
int remove(Queue *pQueue, float* x)
{
    // check for queue underflow
    if (isEmpty(pQueue))
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // remove element decrement queue size by 1
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = pQueue->front;
    *x = temp->data;
    pQueue->front = temp->next;
    pQueue->size--;
    free(temp);
    printf("Removing %f\n", *x);
    return 0;
}
 
// Utility function to peek at first element from the queue
int peek(Queue *pQueue, float* x)
{
    // check for queue underflow
    if (isEmpty(pQueue))
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    // return front of queue value
    *x = pQueue->front->data;
    return 0;
}
 
int main()
{
    // create a queue of capacity 5
    Queue *qt = newQueue();
    float  value;
 
    insert(qt, 1.0);
    insert(qt, 2.0);
    insert(qt, 3.0);
 
    printf("The queue size is %d\n", size(qt));
    peek(qt, &value);
    printf("Top val on queue is %f\n", value);
    remove(qt, &value);
    remove(qt, &value);
    remove(qt, &value);
 
    if (isEmpty(qt)) {
        printf("The queue is empty");
    }
    else {
        printf("The queue is not empty");
    }
 
    return 0;
}