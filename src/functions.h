//Header file which includes the defined constants, structs, enums and stores the defined functions to be used in the other files.
#define MAX_TASKS 10
#define MAX_LENGTH 30

/**
 * Struct which stores a Gantt Task.
 */
typedef struct {
	char name[MAX_LENGTH];
	int start;
	int end;
	int dependencies[10];
    int dependCount;
} GanttTask;

/**
 * Struct which stores a full Gantt Chart.
 * longestName represents the size of the longest task name, for dynamic column printing.
 */
typedef struct {
    GanttTask tasks[MAX_TASKS];
    int longestName;
} GanttChart;

/**
 * Different question types which can be asked
 */
enum questionType{string, integer};

/**
 * Stores user input in a Question Response, to make use of a common function for different output types
 */
typedef struct {
    int Integer;
    char String[MAX_LENGTH];
} QuestionResponse;

/**
 * Different linetypes which can be printed. Used to simplify line printing for the graph.
 */
enum lineType {dotted, solid, top, bottom};

/**
 * Stores chart and code for response from edit function
 */
typedef struct {
    GanttChart chart;
    int code;
} ActionResponse;

/*
 * Function Definitions: example.c
 */
GanttChart getExample();
void checkIfCircular(GanttChart chart, int taskId, int visitedTasks[], int dependentTask);

/*
 * Function Definitions: input.c
 */
GanttChart createChart();
GanttChart createTask(GanttChart chart, int id);
QuestionResponse giveQuestion(char question[], enum questionType type, int min, int max);

/*
 * Function Definitions: print.c
 */
void printGantt(GanttChart chart);

/*
 * Function Definitions: action.c
 */
ActionResponse chartAction(GanttChart chart);
void printDependentTasks(GanttChart chart, int taskId, int visitedTasks[]);
