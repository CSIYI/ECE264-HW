#include<stdio.h>
#include "answer06.h"
#define Track '.'
#define WALL 'X'
void printstep(int change_y, int change_x, int step)
{
  if (change_x == 1 && change_y == 0 )
  {
    printf("E %d\n", step);
  }
  if (change_x == -1 && change_y == 0)
  {
    printf("W %d\n",step);
  }
  if (change_x == 0 && change_y == -1)
  {
    printf("N %d\n", step);
  }
  if (change_x == 0 && change_y == 1)
  {
    printf("S %d\n",step);
  }
}

void direction(char ** Maze, int W, int H, int pos_y, int pos_x, int changeY, int changeX)
{
  int num_step = 1;

    pos_x += changeX;
    pos_y += changeY;
    Maze[pos_y][pos_x] = Track;
    printstep(changeY, changeX,num_step);
    int east =((pos_x + 1) < W) && (Maze[pos_y][pos_x + 1] == ' ');
    int west = ((pos_x - 1) >= 0) && (Maze[pos_y][pos_x - 1] == ' ');
    int north = ((pos_y - 1) >= 0 )&&(Maze[pos_y - 1][pos_x] == ' ');
    int south =((pos_y + 1) < H )&& (Maze[pos_y + 1][pos_x] == ' ');
    
    
    if (east == 0 &&  west == 0 &&  north == 0 && south == 0)
    {
      Maze[pos_y][pos_x] = WALL;  
      

      int reeast = ((pos_x + 1) < W ) &&(Maze[pos_y][pos_x + 1] == Track) ;
      int rewest = ((pos_x - 1) > 0)&& (Maze[pos_y][pos_x - 1] == Track );
      int renorth = ((pos_y - 1) >  0) && (Maze[pos_y - 1][pos_x] == Track );
      int resouth = ((pos_y + 1) < H )&& (Maze[pos_y + 1][pos_x] == Track );
 
       if (reeast)
       {
         direction(Maze, W, H, pos_y, pos_x, 0,1);
       }
       if (rewest)
       {

         direction (Maze, W, H, pos_y, pos_x, 0, -1);
       }
       if (renorth)
       {

         direction (Maze, W, H, pos_y, pos_x, -1, 0);
       }
       if (resouth)
       {

         direction (Maze, W, H, pos_y, pos_x, 1, 0);
       }
       return;
    }
    else
    {
      if (east)
      {
        direction(Maze, W, H, pos_y, pos_x, 0,1);
      }
      if (west)
      {
        direction (Maze, W, H, pos_y, pos_x, 0, -1);
      }
      if (north)
      {
        direction (Maze, W, H, pos_y, pos_x, -1, 0);
       }
      if (south)
      {
        direction (Maze, W, H, pos_y, pos_x, 1, 0);
      }
    }
 
}
void print_directions(char ** maze, int w, int h)
{
  int posx = 0;
  while (maze[0][posx] != ' ')
  {
    posx ++;
  }
  int posy = 0;
  maze[posy][posx] = Track;
  direction(maze, w, h, posy, posx, 1, 0);
}
  
