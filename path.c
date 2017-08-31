#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

#ifndef READPATH_OFF
char * readPath(char * pathFilename) {

	//FILL IN
	int numelem = 0;
	char *temp_str;
	FILE * fptr = fopen(pathFilename, "r");
   // if fopen fails, return false
   	if (fptr == NULL)
   	{
     	fprintf(stderr, "fopen fail\n");
     	return false;
   	}
   	else
   	{
   		char charc = fgetc(fptr);
  		while(charc !=EOF){
				numelem++;
			charc = fgetc(fptr);
 		}
 		//Error possible 
 		temp_str = malloc(numelem+1);
 		rewind(fptr);
   		fscanf(fptr, "%s\n", temp_str);
   	}
   fclose(fptr);
   return temp_str;
}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) {

	//FILL IN
	//
	int rows_i = m->start.xpos ;
	int col_i = m->start.ypos;
	int i = 0;
	while(i<strlen(path)){
		
		switch(path[i]){
			case 'n':  rows_i--;
					  break;
			case 'e': col_i++;
					  break;
			case 's': rows_i++;
					  break;
			case 'w': col_i--;
					  break;
			default : return false;
		}
		if((rows_i >= m->height) || (col_i >= m->width) || (m->maze[rows_i][col_i].type=='#'))
			return false;
		if(m->maze[rows_i][col_i].visited == true){
			return false;
		}
		m->maze[rows_i][col_i].visited = true;
		i++; 
		if(m->maze[rows_i][col_i].type==END)
			return true;
	}
	return false;
}
#endif //#ifndef CHECKPATH_OFF
