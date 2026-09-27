#include <stdio.h>
#include <string.h>
#include "functions.h"

/**
 * Creates an example GanttChart
 * @return GanttChart, chart with example data
 */
GanttChart getExample() { //@TODO change values, assignment states can not use
    GanttChart chart = {0};

    strcpy(chart.tasks[0].name, "Find_Bank");
    chart.tasks[0].start = 1;
    chart.tasks[0].end = 2;

    strcpy(chart.tasks[1].name, "Get_Mortgage_Approval");
    chart.tasks[1].start = 2;
    chart.tasks[1].end = 2;
    chart.tasks[1].dependCount = 1;
    chart.tasks[1].dependencies[0] = 0;

    strcpy(chart.tasks[2].name, "Draw_Down");
    chart.tasks[2].start = 4;
    chart.tasks[2].end = 6;
    chart.tasks[2].dependCount = 2;
    chart.tasks[2].dependencies[0] = 0;
    chart.tasks[2].dependencies[1] = 1;

    strcpy(chart.tasks[3].name, "Build_Foundation");
    chart.tasks[3].start = 3;
    chart.tasks[3].end = 4;
    chart.tasks[3].dependCount = 1;
    chart.tasks[3].dependencies[0] = 2;

    strcpy(chart.tasks[4].name, "Build_Walls");
    chart.tasks[4].start = 4;
    chart.tasks[4].end = 5;

    strcpy(chart.tasks[5].name, "Roof_And_Ceiling");
    chart.tasks[5].start = 5;
    chart.tasks[5].end = 6;
    chart.tasks[5].dependCount = 2;
    chart.tasks[5].dependencies[0] = 3;
    chart.tasks[5].dependencies[1] = 4;

    strcpy(chart.tasks[6].name, "Plumbing");
    chart.tasks[6].start = 7;
    chart.tasks[6].end = 7;
    chart.tasks[6].dependCount = 1;
    chart.tasks[6].dependencies[0] = 5;

    strcpy(chart.tasks[7].name, "Electrics");
    chart.tasks[7].start = 8;
    chart.tasks[7].end = 9;
    chart.tasks[7].dependCount = 1;
    chart.tasks[7].dependencies[0] = 6;

    strcpy(chart.tasks[8].name, "Inspect_Build");
    chart.tasks[8].start = 9;
    chart.tasks[8].end = 10;
    chart.tasks[8].dependCount = 1;
    chart.tasks[8].dependencies[0] = 4;

    strcpy(chart.tasks[9].name, "Snagging");
    chart.tasks[9].start = 10;
    chart.tasks[9].end = 11;
    chart.tasks[9].dependCount = 2;
    chart.tasks[9].dependencies[0] = 7;
    chart.tasks[9].dependencies[1] = 8;

    chart.longestName = 23;

    return chart;
}
