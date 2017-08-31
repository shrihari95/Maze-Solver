#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"

char * solveMaze(Maze * m) {
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

	//FILL IN
	//int rows_i = curpos.xpos;
	//int col_i = curpos.ypos;
	int i = 0;
	char directions[] = {'n', 's', 'e', 'w'};
	MazePos ndir,sdir,edir,wdir;
	MazePos position[] = {ndir,sdir,edir,wdir};
	if((curpos.xpos >= m->width) || (curpos.ypos>= m->height)) 
		return false;
	if((curpos.xpos < 0) || (curpos.ypos < 0))
		return false;
	if(m->maze[curpos.ypos][curpos.xpos].type=='#')
		return false;
	if(m->maze[curpos.ypos][curpos.xpos].visited == true)
		return false;
	if(m->maze[curpos.ypos][curpos.xpos].type == END){
		path[step] = '\0';
		return true;	
	}
	m->maze[curpos.ypos][curpos.xpos].visited = true;
	
	for(i = 0; i<4; i++){
		position[i] =curpos;
		if(directions[i] == 'n')
		{
			position[i].ypos = position[i].ypos - 1;
		}
		if(directions[i] == 's')
		{
			position[i].ypos = position[i].ypos + 1;
		}
		if(directions[i] == 'e')
		{
			position[i].xpos = position[i].xpos + 1;
		}
		if(directions[i] == 'w')
		{
			position[i].xpos = position[i].xpos - 1;
		}
		//curpos = position[i];
		if(depthFirstSolve(m,position[i],path,step+1)){
			path[step] = directions[i];
			return true;
		}
	}
	return false;
}
