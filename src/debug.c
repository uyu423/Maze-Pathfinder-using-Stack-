#include <stdio.h>
#include "head.h"

/* Debugging Function : Output 'Maze Arrary' */
void printMazeStatus(char(*maze)[SIZE], mazeSize *size) {
	int i, j;
	printf("\n** Maze status (After fillWall() Function) **\n");
	putchar('\t');
	for (i = 0; i <= size->width; i++) {
		printf("%2d ", i);
	}
	printf("\n\n");
	for (i = 0; i <= size->height; i++) {
		printf("%d\t", i);
		for (j = 0; j <= size->width; j++) {
			printf("%2c ", maze[i][j]);
		}
		putchar('\n');
	}
}

/* Debugging Function : Output 'mazeSize size', 'mazeSize goal' */
void printMazeSizeTable(mazeSize *size, mazeSize *goal) {
	printf("\n** Maze Size Status status **\n");
	printf("size->height : %d\nsize->width : %d\n", size->height, size->width);
	printf("goal->height : %d\ngoal->width : %d\n", goal->height, goal->width);
	return;
}

/* Debugging Function : Output 'Offsets' */
void printOffset(offset *move) {
	int i;
	printf("\n** Move offset status **\n");
	for (i = 0; i<8; i++) {
		printf("[%d] : %d %d\n", i, move[i].vert, move[i].horiz);
	}
	return;
}
