#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "path.h"
#include "solver.h"
int main(int argc, char ** argv) {
    if (argc != 3) {
        fprintf(stderr, "Wrong number of command line args\n");
        fprintf(stderr, "Usage: ./pa07 mazeFile pathFile\n");
        return EXIT_FAILURE;
    }
   
    Maze * m = readMaze(argv[1]);
   
       
    if (m == NULL) {
        return EXIT_FAILURE;
    }
    char * check = solveMaze(m);
         FILE * check1;
         check1 = fopen(argv[2],"w");
         fprintf(check1, "%s" ,check);
    //char * path = readPath(argv[2]);
    if (check1 == NULL) {
        freeMaze(m);
        free(m);
        return EXIT_FAILURE;
    }


        int i;
        int j;
    for(i=0 ;i < (m->width);i++)
        {
           for(j=0 ; j < (m->height);j++)
{

          m->maze[j][i].visited = false;

}


         }
    if (checkPath(m, check)) {
        printf("Success!\n");
    } else {
        printf("Failure!\n");
    }
   
    //Clean up memory
    freeMaze(m);
        free(m);
        free(check);
    fclose(check1);
   
    return EXIT_SUCCESS;
}