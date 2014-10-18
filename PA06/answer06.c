#include<stdio.h>
#include "answer06.h"

void printstep(int change_x, int change_y, int step)
{
  if (change_x == 1 && change_y == 0 )
  {
    printf("E %d\n", step);
  }
  if (change_x == -1 && change_y == 0)
  {
    printf("W %d\n",step);
  }
  if (change_x == 0 && change_y == 1)
  {
    printf("N %d\n", step);
  }
  if (change_x == 0 && change_y == -1)
  {
    printf("S %d\n",step);
  }
}

void direction(char ** Maze, int W, int H, int pos_y, int pos_x, int changeY, int changeX)
{
  int num_step = 1;
  while(Maze[pos_y][pos_x] != 'X')
  {
    pos_x += changeX;
    pos_y += changeY;
    Maze[pos_y][pos_x] = 'T';
    int east = ((pos_x + 1) < W) && (Maze[pos_y][pos_x + 1] == ' ');
    int west = ((pos_x - 1) > 0) && (Maze[pos_y][pos_x - 1] == ' ');
    int north = ((pos_y - 1) > 0) && (Maze[pos_y - 1][pos_x] == ' ');
    int south = ((pos_y + 1) < H) && (Maze[pos_y + 1][pos_x] == ' ');
    
    
    if (east == 0 &&  west == 0 &&  north == 0 && south == 0)
    {
      Maze[pos_y][pos_x] = 'X';  
      printstep(changeY, changeX,num_step);
      printstep(-changeY, -changeX, num_step);
      return;
    }
    else
    {
      printstep(changeY, changeX, num_step);
      if (east)
      {
        Maze[pos_y][pos_x] = '.';
        direction(Maze, W, H, pos_y, pos_x, 0,1);
      }
      if (west)
      {
        Maze[pos_y][pos_x] = '.';
        direction (Maze, W, H, pos_y, pos_x, 0, -1);
      }
      if (north)
      {
        Maze[pos_y][pos_x] = '.';
        direction (Maze, W, H, pos_y, pos_x, 1, 0);
      }
      if (south)
      {
        Maze[pos_y][pos_x] = '.';
        direction (Maze, W, H, pos_y, pos_x, -1, 0);
      }
    }
  printstep(-changeY, -changeX, num_step);
 
  }
}
void print_directions(char ** maze, int w, int h)
{
  int posx = 0;
  while (maze[0][posx] != ' ')
  {
    posx ++;
  }
  printf("S 1\n");
  maze[0][posx] = '.'; 
  int posy = 0;
  direction(maze, w, h, posy, posx, 1, 0);
  }
  
