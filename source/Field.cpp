#include "Field.h"
#include "ids.h"
#include <stdio.h>
#include "debug.h"

Field::Field(Rage *rage)
  : rage(rage)
{
  for(int i = 0;i < 11*11;i++)
    {
      TRY(rage, rage->setTile(Rage::MAIN, 0, i%11, i/11, NUMBERS, 0));
    }

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
	TRY(rage, rage->setTile(Rage::MAIN, 0, x+2, y+1, NUMBERS, board[x][y]));
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

void swap(int *a1, int *a2, int *b1, int *b2)
{
  int tempA, tempB;
  tempA = *a1; tempB = *b1;
  *a1 = *a2; *b1 = *b2;
  *a2 = tempA; *b2 = tempB;
}

bool
Field::checkSolution(int solution, int x1, int y1, int x2, int y2, int x3, int y3)
{
  // Check range
  if(x1 < 0 || x1 > 6 || x2 < 0 || x2 > 6 || x3 < 0 || x3 > 6
     || y1 < 0 || y1 > 6 || y2 < 0 || y2 > 6 || y3 < 0 || y3 > 6)
    return false;

  // Sort points
  if(x1+y1*7 > x2+y2*7)
    swap(&x1, &x2, &y1, &y2);
  if(x2+y2*7 > x3+y3*7)
    swap(&x2, &x3, &y2, &y3);
  if(x1+y1*7 > x2+y2*7)
    swap(&x1, &x2, &y1, &y2);

  // Check that solutions are on a line
  if(!((x1 == x2 && x2 == x3 && y1 + 1 == y2 && y2 + 1 == y3) // Vertical line
       || (y1 == y2 && y2 == y3 && x1 + 1 == x2 && x2 + 1 == x3) // Horizontal line
       || (x1 + 1 == x2 && x2 + 1 == x3 && y1 + 1 == y2 && y2 + 1 == y3) // Diagonal line down right
       || (x1 - 1 == x2 && x2 - 1 == x3 && y1 + 1 == y2 && y2 + 1 == y3))) // Diagonal line down left
    return false;

  int a = board[x1][y1];
  int b = board[x2][y2];
  int c = board[x3][y3];

  char correct[] = "Correct! %d * %d %s %d = %d\n";
  char plus[] = "+";
  char minus[] = "-";

  if(int corr = checkSolutionInternal(solution, a, b, c))
    {
      switch(corr)
	{
	case 1: printf(correct, a, b, plus, c, solution); break;
	case 2: printf(correct, a, b, minus, c, solution); break;
	case 3: printf(correct, a, c, plus, b, solution); break;
	case 4: printf(correct, a, c, minus, b, solution); break;
	case 5: printf(correct, b, c, plus, a, solution); break;
	case 6: printf(correct, b, c, minus, a, solution); break;
	}

      return true;
    }

  return false;
}

bool
Field::possibleSolutions(int puzzle)
{
  bool solutionFound = false;

  // uncomment to print out all solutions
  // #define PRINT_SOLUTION

  // Horizontal solutions
  for(int y = 0;y < 7;y++)
    for(int x = 0;x < 5;x++)
      {
	if(checkSolutionInternal(puzzle, board[x][y], board[x+1][y], board[x+2][y]))
	  {
	    solutionFound = true;
#ifdef PRINT_SOLUTION
	    printf("SOLUTION: (%d,%d), (%d,%d), (%d,%d)\n", x+1, y+1, x+2, y+1, x+3, y+1);
#endif
	  }
      }

  // Vertical solutions
  for(int y = 0;y < 5;y++)
    for(int x = 0;x < 7;x++)
      {
	if(checkSolutionInternal(puzzle, board[x][y], board[x][y+1], board[x][y+2]))
	  {
	    solutionFound = true;
#ifdef PRINT_SOLUTION
	    printf("SOLUTION: (%d,%d), (%d,%d), (%d,%d)\n", x+1, y+1, x+1, y+2, x+1, y+3);
#endif
	  }
      }

  // Diagonal down right solutions
  for(int y = 0;y < 5;y++)
    for(int x = 0;x < 5;x++)
      {
	if(checkSolutionInternal(puzzle, board[x][y], board[x+1][y+1], board[x+2][y+2]))
	  {
	    solutionFound = true;
#ifdef PRINT_SOLUTION
	    printf("SOLUTION: (%d,%d), (%d,%d), (%d,%d)\n", x+1, y+1, x+2, y+2, x+3, y+3);
#endif
	  }
      }

  // Diagonal down left solutions
  for(int y = 0;y < 5;y++)
    for(int x = 2;x < 7;x++)
      {
	if(checkSolutionInternal(puzzle, board[x][y], board[x-1][y+1], board[x-2][y+2]))
	  {
	    solutionFound = true;
#ifdef PRINT_SOLUTION
	    printf("SOLUTION: (%d,%d), (%d,%d), (%d,%d)\n", x+1, y+1, x, y+2, x-1, y+3);
#endif
	  }
      }

  return solutionFound;
}

int
Field::checkSolutionInternal(int solution, int a, int b, int c)
{
  if(a * b + c == solution)
    return 1;
  if(a * b - c == solution)
    return 2;
  if(a * c + b == solution)
    return 3;
  if(a * c - b == solution)
    return 4;
  if(b * c + a == solution)
    return 5;
  if(b * c - a == solution)
    return 6;

  return 0;
}
