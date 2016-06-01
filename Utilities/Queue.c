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

struct Node {
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes.
struct Node* front = NULL;
struct Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	struct Node* temp =
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		LOG_INFO("Queue is Empty");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

int Front() {
	if(front == NULL) {
		LOG_INFO("Queue is empty\n");
		return -1;
	}
	return front->data;
}

bool isEmpty()
{
	if(front == NULL) return true;
	else return false;
}
