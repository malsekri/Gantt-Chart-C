#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#define clrscr() system("cls")
#else
#define clrscr() system("clear")
#endif

#define MONTH_COUNT 12
#define MONTH_WIDTH 4
#define DEPENDENCY_WIDTH 20
#define C_ROWS 10

/**
 * Prints some type of line.
 * @param type enum linetype, type of line to be printed.
 */
void printLine(enum lineType type, int length) {
    switch(type) {

        case dotted:
            printf("┃");
            for(int i = 0; i < length; i++) printf("╍");

            for(int i = 0; i < MONTH_COUNT; i++) printf("┃╍╍╍╍");
            printf("┃");
            for(int i = 0; i < DEPENDENCY_WIDTH; i++) printf("╍");
            printf("┃\n");
            break;

        case solid:
            printf("┃");
            for(int i = 0; i < length; i++) printf("━");

            for(int j = 0; j < MONTH_COUNT; j++) printf("┃━━━━");
            printf("┃");
            for(int j = 0; j < DEPENDENCY_WIDTH; j++) printf("━");
            printf("┃\n");
            break;

        case top:
            printf("┏");
            for(int i = 0; i < length; i++) printf("━");

            for(int j = 0; j < MONTH_COUNT; j++) printf("┳━━━━");
            printf("┳");
            for(int j = 0; j < DEPENDENCY_WIDTH; j++) printf("━");
            printf("┓\n");
            break;

        case bottom:
            printf("┗");
            for(int i = 0; i < length; i++) printf("━");

            for(int j = 0; j < MONTH_COUNT; j++) printf("┻━━━━");
            printf("┻");
            for(int j = 0; j < DEPENDENCY_WIDTH; j++) printf("━");
            printf("┛\n");
            break;
    }
}

/**
 * Prints task details (ID and Name) for a variable-size column
 * @param id int, id of the task
 * @param input String, name of the task
 * @param length int, size of the column
 */
void printTaskDetails(int id, char input[MAX_LENGTH], int length) {
    int nameWidth = length - 3;
    printf(" %d %-*.*s", id, nameWidth, nameWidth, input);
}

/**
 * Prints per month graph of some task
 * @param task GanttTask, the task to be printed
 * @param length int, size of the initial column
 * @param id int, task ID to be printed
 */
void printTask(GanttTask task, int length, int id) {
    /* Initial column, variable size */
    printf("┃");
    printTaskDetails(id, task.name, length);

    /* Month columns, prints 'XXXX' if that the task is scheduled for that month */
    for(int i = 0; i < MONTH_COUNT; i++)
        (i - task.start >= -1) && (i - task.end <= -1)
        ? printf("┃XXXX") : printf("┃    ");

    printf("┃");
    int cl = 0;
    for(int i = 0; i < task.dependCount; i++, cl += 2)
        printf(" %d", task.dependencies[i]);
    printf("%*c", DEPENDENCY_WIDTH - cl, ' ');

    printf("┃\n");
}

/**
 * Prints a Gantt chart.
 * @param chart GanttChart, chart to be printed.
 */
void printGantt(GanttChart chart) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    clrscr(); // clear console
    chart.longestName += 2; // Add clearance for ID printing

    printLine(top, chart.longestName);

    /* Print size of task column */
    printf("┃%*c", chart.longestName, ' ');

    /* Print compact month columns so the chart fits a standard terminal. */
    const char *months[MONTH_COUNT] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    for(int i = 0; i < MONTH_COUNT; i++)
        printf("┃%-4s", months[i]);
    printf("┃ %-*s┃\n", DEPENDENCY_WIDTH - 1, "Depends");

    /* Prints tasks and in-between lines */
    for(int i = 0; i < C_ROWS; i++) {
        printLine(dotted, chart.longestName);
        printTask(chart.tasks[i], chart.longestName, i);
    }

    printLine(bottom, chart.longestName);
}