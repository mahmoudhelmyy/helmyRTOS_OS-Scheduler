# helmyOS - Real-Time Operating System (RTOS)

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Getting Started](#getting-started)


## Project Overview

helmyOS is a lightweight and simple Real-Time Operating System (RTOS) designed for embedded systems and applications with specific timing and task scheduling requirements. This repository contains the source code and documentation for the helmyOS RTOS.

## Features

- **Task Management:** Create, suspend, resume, and delete tasks with specific priorities.
- **Task Scheduling:** Tasks are scheduled based on their priorities, periodicity, and initial delay.
- **SysTick Timer:** Utilizes the SysTick timer for task scheduling and execution.

## Getting Started

1. Clone this repository to your development environment.

   ```bash
   git clone https://github.com/yourusername/helmyOS-RTOS.git
   ```
2. Initialize and start the RTOS:
    ```bash
    helmyRTOS_Start();
    ```
3. Create tasks with specific priorities, periodicity, and task functions:
    ```bash
    helmyRTOS_CreateTask(Priority, Periodicity, TaskFunction, FirstDelay);
    ```

4. Implement your task functions:
    ```bash
    void TaskFunction(void) {
        // Your task logic here
    }
    ```
