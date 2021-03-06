#include "rpi-sched.h"
#define NULL 0
//typedef int (*myFuncDef)(void);

struct node createNode (int id, int (*myFuncDef)(void)){
	struct node singleNode;
	singleNode.next = NULL;
	singleNode.registeredFunPtr = myFuncDef;
	singleNode.task_id = id;
	return singleNode;
}

void addNodeEnd(struct node *addNode, struct node *head){
	struct node *temp;
	temp = head;
	if (temp->next != NULL){
		addNodeEnd(addNode,head->next);
	}
	else{
		temp->next = addNode;
	}
}
