/*
 * scheduler.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Thuan
 */


#include "scheduler.h"

TaskList_t TaskList;
uint32_t TaskIDCounter = 0;

void SCH_Init()
{
	TaskList.head = NULL;
	TaskList.size = 0;
}

void SCH_Update()
{

	if(TaskList.size && TaskList.head->Delay > 0) TaskList.head->Delay--;
}

void addTask(TaskControlBlock_t * task)
{
    if(TaskList.size >= SCH_MAX_TASKS)
    {
        return;
    }
    if(TaskList.size == 0){
        TaskList.head = task;
        TaskList.size++;
        return;
    }

    TaskControlBlock_t * curr = TaskList.head;
    TaskControlBlock_t * prev = NULL;
    int found = 0;
    while(!found)
    {
        if(curr != NULL && task-> Delay >= curr-> Delay)
        {
            task -> Delay -= curr -> Delay;
            prev = curr;
            curr = curr -> NextTask;
        }
        else
        {
            task -> NextTask = curr;

            if(prev != NULL) prev->NextTask = task;
            else TaskList.head = task;

            if(curr != NULL) curr -> Delay -= task->Delay;
            TaskList.size++;
            found = 1;
        }
    }
    return;
}

void SCH_Add_Task(void (*functionPointer)(), unsigned int DELAY, unsigned int PERIOD)
{
	TaskControlBlock_t * task = (TaskControlBlock_t *)malloc(sizeof(TaskControlBlock_t));

	task -> Delay 		= DELAY;
	task -> Period 		= PERIOD;
	task -> TaskID 		= (++TaskIDCounter)%256;
	task -> TaskPointer = functionPointer;
	task -> NextTask 	= NULL;

	addTask(task);
}

void SCH_DeleteTask(uint32_t ID)
{
	if(TaskList.size == 0)
	{
		return;
	}

	TaskControlBlock_t * curr = TaskList.head;
	TaskControlBlock_t * prev = NULL;

	while(curr != NULL)
	{
		if(ID == curr -> TaskID)
		{
			if(prev == NULL && curr -> NextTask == NULL)
			{
				free(curr);
				TaskList.head = NULL;
				TaskList.size--;
				curr = NULL;
			}
			else if (prev == NULL)
			{
				curr -> NextTask -> Delay += curr -> Delay;
				TaskList.head = curr -> NextTask;
				free(curr);
				TaskList.size--;
				curr = NULL;
			}
			else if (curr -> NextTask == NULL)
			{
				free(curr);
				prev -> NextTask = NULL;
				TaskList.size--;
				curr = NULL;
			}
			else
			{
				curr -> NextTask -> Delay += curr -> Delay;
				prev -> NextTask = curr -> NextTask;
				curr -> NextTask = NULL;
				free(curr);
				TaskList.size--;

				curr = NULL;
			}

		}
		else
		{
			prev = curr;
			curr = curr -> NextTask;
		}
	}
}



void SCH_Dispatcher(){
	while(TaskList.size != 0 &&TaskList.head -> Delay == 0){
		(*TaskList.head -> TaskPointer)();
		if(TaskList.head -> Period) SCH_Add_Task(TaskList.head -> TaskPointer, TaskList.head -> Period, TaskList.head -> Period);
		SCH_DeleteTask(TaskList.head -> TaskID);
	}
}
