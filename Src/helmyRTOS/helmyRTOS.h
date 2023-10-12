/*================================================================
 *	Project Name: helmyOS
 * 	File Name: RTOS.h
 * 	Created on: Sep 12, 2023
 * 	Author: HELMY-PC
 *================================================================
 *  					File Description
 *================================================================
 *
 */

#ifndef HELMYRTOS_HELMYRTOS_H_
#define HELMYRTOS_HELMYRTOS_H_
#include "STM32F103C8T6.h"

#include "helmyRTOS_Cfg.h"

typedef struct{
uint16  Periodicity;
void (*TaskHandler)(void);
uint16  FirstDelay;
uint8   State;
}TASK_TCB ;

#define TASK_READY       0U
#define TASK_SUSPEND     1U

void helmyRTOS_Scheduler(void);
void helmyRTOS_Start( void );
void helmyRTOS_CreateTask(uint8 Priority ,uint16 Periodicity, void (*vTask)(void),uint16 FirstDelay );
void helmyRTOS_SuspendTask (uint8 TaskID);
void helmyRTOS_ResumeTask  (uint8 TaskID);
void helmyRTOS_DeleteTask  (uint8 TaskID);

#endif /* HELMYRTOS_HELMYRTOS_H_ */
