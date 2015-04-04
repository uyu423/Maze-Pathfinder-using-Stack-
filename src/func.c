#include <stdio.h>
#include "head.h"

/* Other C File's Function Extern */
element stackPop(stackManager *stackMgr);	//stack.c

/* Maze Path Finding Function using Stack */
/* StackMgr included Stack Structure(element *stack) */
void pathFinder(char(*maze)[SIZE], mazeSize *goal, stackManager *stackMgr, offset *move) {
	char mark[60][60];
	int i, row, col, nextRow, nextCol, dir;
	bool found = false;
	element position;
	stackMgr->stack[0].row = 1;
	stackMgr->stack[0].col = 1;
	stackMgr->stack[0].dir = 1;
	stackMgr->top++;
	mark[1][1] = '1';
	while (stackMgr->top > -1 && !found) {
		position = stackPop(stackMgr);
		row = position.row;
		col = position.col;
		dir = position.dir;
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (nextRow == goal->height && nextCol == goal->width) {
				found = true;
			}
			else if (maze[nextRow][nextCol] != '1' && mark[nextRow][nextCol] != '1') {
				mark[nextRow][nextCol] = '1';
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				stackPush(stackMgr, position);
				row = nextRow;
				col = nextCol;
				dir = 0;
			}
			else {
				dir++;
			}
		}
	}
	printResult(found, row, col, goal, stackMgr);
	return;
}

/* if succeed found GOAL, print path. but not found , print other Message. */
void printResult(bool found, int row, int col, mazeSize *goal, stackManager *stackMgr) {
	int i;
	if(!found) {
		printf("\n** The maze dose not have a path **\n\n");
		return;
	}
	else {
		printf("\n** The maze dose have a path **\n");
		printf("(%d, %d)", (goal->height)-1, (goal->width)-1);
		printf("<-(%d, %d)", row-1, col-1);
		for(i=stackMgr->top; i>=0; i--) {
			printf("<-(%d, %d)", (stackMgr->stack[i].row)-1, (stackMgr->stack[i].col)-1);
		}
		printf("\n\n");
	}
}

/* Input file (Miro.txt) Descriptor Generator */
int readFile(FILE **fp) {
	if (!(*fp = fopen(FILENAME, "r"))) {
		perror("Maze Flie Open Error : ");
		return 1;
	}
	return 0;
}

/* Make 'Maze Array' by 'maze.txt' start index was [1, 1] */
mazeSize inputMaze(char(*maze)[SIZE], FILE **fp, mazeSize *size) {
	int trash;
	char tmpByte = '\0';
	int tmpWidth = 0;
	
	/* Drop Index Value */
	fscanf(*fp, "%d", &trash); //first Index value
	fgetc(*fp);	//Space value 
	fscanf(*fp, "%d", &trash); //second Index value
	fgetc(*fp);	//Enter value
	
	while (!feof(*fp)) {
		tmpByte = fgetc(*fp);
		if (tmpByte == ' ') {
			continue;
		}
		else if (tmpByte == 10) {
			size->height++;
			tmpWidth = size->width;
			size->width = 0;
			continue;
		}
		else {
			maze[size->height][++(size->width)] = tmpByte;
			continue;
		}
	}
	size->width = tmpWidth + 1;

	return *size;
}

/* i, j were 0 line and i, j were end line fill '1'(wall)  */
void fillWall(char(*maze)[SIZE], mazeSize *size) {
	int i;
	for (i = 0; i <= size->width; i++) {
		maze[0][i] = '1';
		maze[size->height][i] = '1';
	}
	for (i = 0; i <= size->height; i++) {
		maze[i][0] = '1';
		maze[i][size->width] = '1';
	}
}

/* set Goal Index : mazeSize size value -1 */
mazeSize setGoal(mazeSize *size, mazeSize *goal) {
	goal->height = size->height - 1;
	goal->width = size->width - 1;
	return *goal;
}

/* Offset Value Set. ref. Fundamentals of Data Structures in C 131p */
void setOffset(offset *move) {
	move[N].vert = -1;	move[N].horiz = 0;
	move[NE].vert = -1; move[NE].horiz = 1;
	move[E].vert = 0;	move[E].horiz = 1;
	move[SE].vert = 1;	move[SE].horiz = 1;
	move[S].vert = 1;	move[S].horiz = 0;
	move[SW].vert = 1;	move[SW].horiz = -1;
	move[W].vert = 0;	move[W].horiz = -1;
	move[NW].vert = -1;	move[NW].horiz = -1;
	return;
}
