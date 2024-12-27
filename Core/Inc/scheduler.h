/*
 * scheduler.h
 *
 *  Created on: Nov 27, 2024
 *      Author: Thuan
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#include <stdlib.h>

#define SCH_MAX_TASKS  32


struct TaskControlBlock_t
{
	void (*TaskPointer)();
    uint32_t TaskID;
    uint32_t Delay;
    uint32_t Period;

    struct TaskControlBlock_t *NextTask;
};

typedef struct TaskControlBlock_t TaskControlBlock_t;

typedef struct
{
    TaskControlBlock_t * head;
    int size;
} TaskList_t;


void SCH_Init();
void SCH_Add_Task(void (*functionPointer)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Update();
void SCH_Dispatcher();
void SCH_DeleteTask(uint32_t ID);


#endif /* INC_SCHEDULER_H_ */
