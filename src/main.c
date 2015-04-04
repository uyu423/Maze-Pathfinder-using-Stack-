/*
*	ProjectName	: DSB Proj.1 Maze Finder (Stack)
*	Corder 		: Yu Yongwoo (YoWu)
*	Organiz.	: Catholic Univ. of Korea
*	Major		: Computer Science (Minor : Infomation System Eng)
*	StudentNum	: 201021395
*	DateTime	: 2015.4.1(Mon) 13:34
*	Contact		: uyu423@gmail.com (http://luckyyowu.tistory.com)
*	Develop OS	: CentOS Linux 6.6 x86 (kernel 2.6.32-504)
*	PorgramLang	: C (Library Model : POSIX)
*	TextEditor	: VIM - Vi IMproved 7.2
*	Encording	: UTF-8 (Linux Basic)
*	Compiler	: GCC 4.4.7
*/

#include "./head.h"

int main(void) {
	FILE *fp = NULL;
	char maze[SIZE][SIZE];
	offset move[8];
	stackManager stackMgr;
	mazeSize goal, size = { 0, 1 };
	
	if (readFile(&fp)) { return 1; }
	size = inputMaze(maze, &fp, &size);
	goal = setGoal(&size, &goal);
	fillWall(maze, &size);
	setOffset(move);
	makeStack(&stackMgr);
//	printOffset(move);	/* print 'move' offsets for Debugging */
//	printMazeSizeTable(&size, &goal); /* print 'goal', 'size' mazeSize offset for Debugging */
//	printMazeStatus(maze, &size);	/* print Maze Map for Debugging */
	pathFinder(maze, &goal, &stackMgr, move);

	
	return 0;
}
