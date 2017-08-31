#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename) {
	//FILL IN
	Maze* inst = malloc(sizeof(Maze));
	MazeSquare * * maze1;
	int i = 0;
	int rows_i = 0;
	int col_i = 0;
	char ch1;
	//Maze t;
	FILE * fptr = fopen(mazeFilename, "r");
   // if fopen fails, return false
   	if (fptr == NULL)
   	{
     	fprintf(stderr, "fopen fail\n");
     	return false;
   	}
   	else{
   		//check return value
		fscanf(fptr, "%d", &inst->height);
		fseek(fptr, 1, SEEK_CUR);
		fscanf(fptr, "%d\n", &inst->width);
		maze1 = malloc(inst->height * sizeof(MazeSquare *));
		for (i = 0; i < inst->height; i++)
		{
 			maze1[i] = malloc(inst->width * sizeof(MazeSquare));
		}
		for(rows_i = 0;rows_i < inst->height;rows_i++)
		{
			for(col_i = 0;col_i <= inst->width; col_i++)
			{

				if((ch1=fgetc(fptr))=='\n'){
					continue;
				}
				maze1[rows_i][col_i].visited = false;
				maze1[rows_i][col_i].type = ch1;
				if(ch1 == 's'){
					inst->start.xpos = rows_i;
					inst->start.ypos = col_i;
				}
				if(maze1[rows_i][col_i].type == 'e'){
					inst->end.xpos = rows_i;
					inst->end.ypos = col_i;
				}
			}
		}
	}
	inst ->maze = maze1;
	fclose(fptr);

	return inst;
}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
	//1. Free each of the "rows" of the maze
	int i = 0;
	//2. Free the "spine" of the array
	for (i = 0; i < m->height; i++) {
  		free(m->maze[i]);
	}
	free(m->maze);
}
#endif //#ifndef FREEMAZE_OFF
