# Gantt-Chart-C

A small C command-line application for creating and viewing project schedules as Gantt charts.

## Features

- Create a schedule with up to 10 tasks.
- Set a start and end month for each task.
- Record task dependencies.
- Display the schedule from January to December.
- Edit tasks after creating a chart.
- Trace dependency chains and report circular dependencies.
- Load a built-in construction project example.

## Requirements

- GCC
- Windows, Linux, or macOS terminal

The program uses standard C libraries. On Windows, the application configures the console for UTF-8 so the chart borders display correctly.

## Build and Run

From the project root, compile all source files:

```text
gcc src/main.c src/action.c src/example.c src/input.c src/print.c -o Gantt-Chart-C
```

On Windows, run:

```text
.\Gantt-Chart-C.exe
```

On Linux or macOS, run:

```text
./Gantt-Chart-C
```

The VS Code build task also builds the complete application. Open the Command Palette and choose `Tasks: Run Build Task`.

## Usage

At startup:

- Enter `0` to create a new chart.
- Enter `1` to load the example chart.

After the chart is displayed:

- Enter `0` to edit a task.
- Enter `1` to test a dependency chain.
- Enter `2` to quit.

Task IDs are zero-based, so the first row is task `0`.

## Project Structure

```text
src/
  action.c       Chart editing and dependency testing
  example.c      Built-in example chart
  functions.h    Shared data structures and declarations
  input.c        User input and validation
  main.c         Program entry point
  print.c        Gantt chart rendering
```

## License

This project was created for educational purposes.
