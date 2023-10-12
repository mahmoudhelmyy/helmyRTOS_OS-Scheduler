/*================================================================
 *  Project Name: helmyOS
 *  File Name: RTOS.c
 *  Created on: Sep 12, 2023
 *  Author: HELMY-PC
 *================================================================
 *                      File Description
 *================================================================
 *  This file contains the implementation of a simple real-time
 *  operating system (RTOS) for helmyOS.
 *================================================================*/

#include "helmyRTOS.h"

#include "../MCAL/Systick/Systick.h"

/* Define the maximum number of tasks supported by the RTOS. */
static TASK_TCB SysTasks[TASK_NUMBERS] = {{NULL}};

/**
 * @brief Starts the RTOS by initializing the SysTick timer and setting its callback function for task scheduling.
 */
void helmyRTOS_Start(void) {
    /* Set the callback function for the SysTick timer. */
    MCAL_Systick_SetCallBack(helmyRTOS_Scheduler);

    /* Initialize the SysTick timer. */
    MCAL_Systick_Init();

    MCAL_Systick_Start(TICK_TIME);
}
/**
 * @brief Creates a new task with the specified parameters.
 *
 * @param Priority Task priority (0 to TASK_NUMBERS-1).
 * @param Periodicity Time between task executions in milliseconds.
 * @param vTask Pointer to the task function to execute.
 * @param FirstDelay Initial delay before the task starts executing.
 */
void helmyRTOS_CreateTask(uint8 Priority, uint16 Periodicity, void (*vTask)(void), uint16 FirstDelay) {
    /* Check if the task slot is available. */
    if (SysTasks[Priority].TaskHandler == NULL) {
        /* Initialize task parameters. */
        SysTasks[Priority].Periodicity = Periodicity;
        SysTasks[Priority].TaskHandler = vTask;
        SysTasks[Priority].FirstDelay = FirstDelay;
        SysTasks[Priority].State = TASK_READY;
    } else {
        /* Task slot is already used. Do nothing in this case. */
    }
}

/**
 * @brief Suspends a task with the given TaskID.
 *
 * @param TaskID ID of the task to suspend.
 */
void helmyRTOS_SuspendTask(uint8 TaskID) {
    SysTasks[TaskID].State = TASK_SUSPEND;
}

/**
 * @brief Resumes a suspended task with the given TaskID.
 *
 * @param TaskID ID of the task to resume.
 */
void helmyRTOS_ResumeTask(uint8 TaskID) {
    SysTasks[TaskID].State = TASK_READY;
}

/**
 * @brief Deletes a task with the given TaskID.
 *
 * @param TaskID ID of the task to delete.
 */
void helmyRTOS_DeleteTask(uint8 TaskID) {
    SysTasks[TaskID].TaskHandler = NULL;
}

/**
 * @brief Task scheduler that handles task execution based on their priorities, periodicity, and first delay.
 */
void helmyRTOS_Scheduler(void) {
    uint8 TaskCounter;
    /* Iterate through all defined tasks. */
    for (TaskCounter = 0; TaskCounter < TASK_NUMBERS; TaskCounter++) {
        /* Check if the task is defined and ready to run. */
        if ((SysTasks[TaskCounter].TaskHandler != NULL) && (SysTasks[TaskCounter].State == TASK_READY)) {
            /* Check if it's time to execute the task. */
            if (SysTasks[TaskCounter].FirstDelay == 0) {
                /* Reset the delay and execute the task. */
                SysTasks[TaskCounter].FirstDelay = SysTasks[TaskCounter].Periodicity - 1;
                SysTasks[TaskCounter].TaskHandler();
            } else {
                /* Decrement the delay counter. */
                SysTasks[TaskCounter].FirstDelay--;
            }
        } else {
            /* Task is not defined or not ready. Do nothing for this task. */
        }
    }
}
