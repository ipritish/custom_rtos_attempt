#include "rpi-sched.h"
#define NULL 0
//typedef int (*myFuncDef)(void);

struct node createNode (int (*myFuncDef)(void)){
	struct node singleNode;
	singleNode.next = NULL;
	singleNode.registeredFunPtr = myFuncDef;
	return singleNode;
}
