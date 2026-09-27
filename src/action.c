#include <stdio.h>
#include "functions.h"

/**
 * Provides user option to edit or test some chart
 * @see input.c#giveQuestion
 * @param chart GanttChart, data of chart
 */
ActionResponse chartAction(GanttChart chart) {
    ActionResponse response = {chart, 0};

    /* Take user input on action he wishes to perform on the chart */
    int input = giveQuestion("Enter '0' to edit chart. Enter '1' to run test. Enter '2' to quit. Input: ", integer, 0, 2).Integer;
    int val = 0;
    int visitedTasks[10] = {0};

    switch(input) {
        case 0: /* Edit Chart */
            val = giveQuestion("Please enter ID of task to edit (0-9): ", integer, 0, 9).Integer;
            response.chart = createTask(chart, val);
            response.code = 1;
            return response;

        case 1: /* Test Chart */
            val = giveQuestion("Please enter ID of task to test (0-9): ", integer, 0, 9).Integer;
            printf("Dependency chain: ");
            printDependentTasks(chart, val, visitedTasks);
            printf("\n");
            val = giveQuestion("Enter '1' to show the chart again or '2' to quit. Input: ", integer, 1, 2).Integer;
            response.code = val == 1 ? 1 : 0;
            return response;

        default: /* Quit All */
            break;
    }

    return response;
}

//checkIfCircular function that ensures whether a circular dependency is found for a specific task.
void checkIfCircular(GanttChart chart, int taskId, int visitedTasks[], int dependentTask) {
    visitedTasks[taskId] = 1;
    for (int i = 0; i < chart.tasks[taskId].dependCount; i++)
    {
        int dependentTaskId = chart.tasks[taskId].dependencies[i];

        if (dependentTaskId == dependentTask) {
            printf("!!! Circular Dependency Found !!!");
            return;
        }
        else  { //(visitedTasks[dependentTaskId] == 0)
            checkIfCircular(chart, taskId, visitedTasks, dependentTask);
        }
    }
}

//printDependentTasks function that prints a certain tasks dependent tasks and then checks
//for potential circular dependency.
void printDependentTasks(GanttChart chart, int taskId, int visitedTasks[])
{
    if (visitedTasks[taskId] == 1) {
        printf("[circular dependency at %d]", taskId);
        return;
    }

    if (visitedTasks[taskId] == 2) return;

    printf("%d -> ", taskId);
    visitedTasks[taskId] = 1;

    for (int i = 0; i < chart.tasks[taskId].dependCount; i++) {
        int dependentTaskId = chart.tasks[taskId].dependencies[i];

        if (dependentTaskId < 0 || dependentTaskId >= MAX_TASKS) {
            printf("[invalid task %d] ", dependentTaskId);
        }
        else {
            printDependentTasks(chart, dependentTaskId, visitedTasks);
        }
    }

    visitedTasks[taskId] = 2;
}