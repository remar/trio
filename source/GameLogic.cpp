#include "GameLogic.h"
#include "ids.h"
#include <stdio.h>

GameLogic::GameLogic(Rage *rage, Input *input)
  : rage(rage), input(input), win(false), resultTimer(0), wins(0), fails(0)
{
  field = new Field(rage);

  field->randomize();

  markers[0].selected = markers[1].selected = markers[2].selected = false;
  currentMarker = 0;

  newPuzzle();
}

void
GameLogic::update()
{
  ticks++;

  if(resultTimer > 0)
    {
      if(--resultTimer == 0)
	{
	  if(win)
	    {
	      printf("Correct!\n");
	      wins++;
	    }
	  else
	    {
	      printf("Fail!\n");
	      fails++;
	    }

	  printf("Wins: %d, Fails: %d, Rank: %d\n", wins, fails, wins?ticks/wins/60:0);

	  for(int i = 0;i < 3;i++)
	    {
	      rage->removeSpriteInstance(Rage::MAIN, markers[i].spriteID);
	      markers[i].selected = false;
	    }

	  newPuzzle();
	}
    }

  if(input->keyPressed(KEY_TOUCH))
    {
      int x, y;
      input->getTouch(&x, &y);
      x /= 24;
      y /= 24;

      if(x >= 2 && x <= 8 && y >= 1 && y <= 7)
	{
	  x -= 2; y -= 1;
	  // Player selected board position x, y

	  // Has the player selected this spot previously
	  bool unselect = false;
	  for(int i = 0;i < 3;i++)
	    {
	      if(markers[i].selected && markers[i].x == x && markers[i].y == y)
		{
		  rage->removeSpriteInstance(Rage::MAIN, markers[i].spriteID);
		  markers[i].selected = false;
		  unselect = true;
		}
	    }

	  if(!unselect)
	    {
	      int i;
	      for(i = 0;i < 3;i++)
		if(markers[i].selected == false)
		  break;

	      markers[i].x = x;
	      markers[i].y = y;
	      markers[i].spriteID = rage->createSpriteInstance(Rage::MAIN, MARKER);
	      rage->moveSpriteAbs(Rage::MAIN, markers[i].spriteID, (x+2)*24+4, (y+1)*24+4);
	      markers[i].selected = true;
	    }

	  // Check if all marks are placed
	  if(markers[0].selected == true
	     && markers[1].selected == true
	     && markers[2].selected == true)
	    {
	      win = field->checkSolution(puzzle,
					 markers[0].x, markers[0].y,
					 markers[1].x, markers[1].y,
					 markers[2].x, markers[2].y);

	      resultTimer = 30;
	    }
	}
    }  

  if(input->keyPressed(KEY_A))
    {
      field->randomize();
      newPuzzle();
    }
}

void
GameLogic::newPuzzle()
{
  // TODO: Make sure that there actually is a solution for this puzzle
  // on the board

  do
    {
      puzzle = rand() % 50 + 1;
    }
  while(!field->possibleSolutions(puzzle));

  printf("\nPlease find %d somewhere!\n", puzzle);
}

