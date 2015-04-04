#include <stdio.h>
#include <stdlib.h>
#define FILENAME "maze.txt"
#define SIZE 60
typedef enum { N, NE, E, SE, S, SW, W, NW } direction;
typedef enum { false, true } bool;

/* need Struction define */
typedef struct __mazeSize {
	int width;
	int height;
} mazeSize;
typedef struct __offset {
	int vert;
	int horiz;
} offset;
typedef struct __stackElement {
	int row;
	int col;
	int dir;
} element;
typedef struct __stackManager {
	element *stack;
	int size;
	int top;
} stackManager;

/* Define Basic Functions */
int readFile(FILE **fp);
mazeSize inputMaze(char(*maze)[SIZE], FILE **fp, mazeSize *size);
mazeSize setGoal(mazeSize *size, mazeSize *goal);
void fillWall(char(*maze)[SIZE], mazeSize *size);
void setOffset(offset *move);
void pathFinder(char(*maze)[SIZE], mazeSize *goal, stackManager *stackMgr, offset *move);
void printResult(bool found, int row, int col, mazeSize *goal, stackManager *stackMgr);

/* Define Stack Function */
void stackPush(stackManager *stackMgr, element item);
void makeStack(stackManager *stackMgr);
bool stackEmpty(stackManager *stackMgr);
bool stackFull(stackManager *stackMgr);
element stackPop(stackManager *stackMgr);

/* Define Debugging Functions */
void printMazeStatus(char(*maze)[SIZE], mazeSize *size);
void printMazeSizeTable(mazeSize *size, mazeSize *goal);
void printOffset(offset *move);
