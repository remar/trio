#include "Field.h"
#include "ids.h"
#include <stdio.h>

Field::Field(Rage *rage)
  : rage(rage)
{
  for(int i = 0;i < 11*8;i++)
    rage->setTile(Rage::MAIN, 0, i%11, i/11, NUMBERS, 0);

  //                1  2  3  4  5  6  7  8  9
  int numbers[9] = {5, 6, 6, 6, 6, 6, 5, 5, 4};
  int current = 0;

  for(int i = 0;i < 7*7;i++)
    {
      board[i%7][i/7] = current + 1;

      if(--numbers[current] == 0)
	{
	  current++;
	}
    }

  drawBoard();
}

void
Field::drawBoard()
{
  for(int y = 0;y < 7;y++)
    for(int x = 0;x < 7;x++)
      {
	rage->setTile(Rage::MAIN, 0, x+2, y+1, NUMBERS, board[x][y]);
      }
}

void
Field::randomize()
{
  // Fisher-Yates
  for(int i = 7*7 - 1;i >= 1;i--)
    {
      int j = rand()%i;
      
      int temp = board[i%7][i/7];
      board[i%7][i/7] = board[j%7][j/7];
      board[j%7][j/7] = temp;
    }

  drawBoard();
}

bool
Field::checkSolution(int x1, int y1, int x2, int y2, int x3, int y3)
{
  // Check range
  if(x1 < 0 || x1 > 6 || x2 < 0 || x2 > 6 || x3 < 0 || x3 > 6
     || y1 < 0 || y1 > 6 || y2 < 0 || y2 > 6 || y3 < 0 || y3 > 6)
    return false;

  // TODO: Check that solutions are on a line

  int a = board[x1][y1];
  int b = board[x2][y2];
  int c = board[x3][y3];

  printf("%d * %d + %d = %d\n", a, b, c, a * b + c);
  printf("%d * %d + %d = %d\n", a, c, b, a * c + b);
  printf("%d * %d + %d = %d\n", b, c, a, b * c + a);

  return false;
}
