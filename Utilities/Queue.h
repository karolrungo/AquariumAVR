/*
 * Queue.h
 *
 *  Created on: 31 maj 2016
 *      Author: Karol
 */

#ifndef UTILITIES_QUEUE_H_
#define UTILITIES_QUEUE_H_

#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct Queue
{
	Node* front;
	Node* tail;
} Queue;

void enqueue(Queue* p_queue, uint8_t x);
void dequeue(Queue* p_queue);
int front(const Queue p_queue);
bool isEmpty(const Queue p_queue);

#endif /* UTILITIES_QUEUE_H_ */
