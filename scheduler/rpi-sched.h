#ifndef RPI_SCHED_H
#define RPI_SCHED_H

struct node{
	int task_id;	
	int (*registeredFunPtr)(void);
	struct node *next;
};

#endif
