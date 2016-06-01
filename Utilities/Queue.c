/*
 * Queue.c
 *
 *  Created on: 31 maj 2016
 *      Author: Karol
 */

/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>

#include "Queue.h"
#include "Logger.h"

void enqueue(Queue* p_queue, uint8_t x)
{
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = NULL;
	if(p_queue->front == NULL && p_queue->tail == NULL)
	{
		p_queue->front = p_queue->tail = temp;
		return;
	}
	p_queue->tail->next = temp;
	p_queue->tail = temp;
}


void dequeue(Queue* p_queue)
{
	struct Node* temp = p_queue->front;

	if(p_queue->front == NULL)
	{
		LOG_INFO("Queue is Empty");
		return;
	}
	if(p_queue->front == p_queue->tail)
	{
		p_queue->front = p_queue->tail = NULL;
	}
	else
	{
		p_queue->front = p_queue->front->next;
	}
	free(temp);
}

int front(const Queue p_queue)
{
	if(p_queue.front == NULL) {
		LOG_INFO("Queue is empty\n");
		return -1;
	}
	return p_queue.front->data;
}

bool isEmpty(const Queue p_queue)
{
	return (p_queue.front == NULL) ? true : false;
}
