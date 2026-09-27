#include <stdio.h>
#include <string.h>
#include "functions.h"

/**
 * Prints some question to the user to obtain his input
 * @param question char[], question String to ask the user
 * @param type questionType, either string or integer, determines error checking
 * @param min int, used for integer type only, minimum allowed value (inclusive)
 * @param max int, used for integer type only, maximum allowed value (inclusive)
 * @return QuestionResponse, response struct containing the user's input
 */
QuestionResponse giveQuestion(char question[], enum questionType type, int min, int max) {
    QuestionResponse response;
    printf("%s", question);

    /* Loops until user enters correct response */
    while(1) {
        switch(type) {
            case string:
                getchar();
                fgets(response.String, MAX_LENGTH, stdin);
                if(strchr(response.String, '\n') == NULL) {
                    int character;
                    while((character = getchar()) != '\n' && character != EOF) { }
                }
                response.String[strcspn(response.String, "\r\n")] = '\0';
                return response;

            case integer:
                scanf("%d", &response.Integer);
                if(response.Integer >= min && response.Integer <= max) return response;
                printf("Invalid input! Please enter an integer (%d-%d): ", min, max);
                continue;
        }
    }
}

/**
 * Creates new task data from user input. Replaces existing task of ID.
 * @param chart GanttChart, chart data to edit
 * @param id int, ID of task to write/overwrite
 * @return GanttChart, updated chart data
 */
GanttChart createTask(GanttChart chart, int id) {
    QuestionResponse working;

    /* Take user input for the task's name */
    working = giveQuestion("Please enter the task name: ", string, 0, 0);
    strcpy(chart.tasks[id].name, working.String);

    /* Update longestName if new string is longer */
    int length = (int) strlen(chart.tasks[id].name);
    if(length > chart.longestName) chart.longestName = length + 1;

    /*Take user input for start month and end month */
    chart.tasks[id].start = giveQuestion("Please enter the start month (1-12): ", integer, 1, 12).Integer;
    chart.tasks[id].end = giveQuestion("Please enter the end month (1-12): ", integer, 1, 12).Integer;

    /* Ask user for amount of dependencies, take in dependencies */
    chart.tasks[id].dependCount = giveQuestion("Please enter the amount of relations to add (0-10): ", integer, 0, 10).Integer;
    for(int j = 0; j < chart.tasks[id].dependCount; j++) {
        working = giveQuestion("Please enter ID number of task relation: ", integer, 0, 9);
        chart.tasks[id].dependencies[j] = working.Integer;
    }

    return chart;
}

/**
 * Creates a GanttChart from user input
 * @param numTasks int, amount of tasks to create
 * @return GanttChart, struct instance of data user input
 */
GanttChart createChart() {
    GanttChart chart = {0};
    chart.longestName = 11; // Ensures minimum of 12-wide column

    /* Ask user how many tasks he would like to input */
    int taskCount = giveQuestion("Please enter amount of tasks to add (1-10): ", integer, 1, 10).Integer;

    /* Take user input for tasks */
    for(int i = 0; i < taskCount; i++) chart = createTask(chart, i);

    chart.longestName += 1; //Ignores end line character included with string
    return chart;
}
