#include "GameLogic.h"
#include "ids.h"
#include <stdio.h>

GameLogic::GameLogic(Rage *rage, Input *input)
  : rage(rage), input(input), win(false), resultTimer(0), wins(0), fails(0)
{
  field = new Field(rage);

  field->randomize();

  largeMarker = 0;

  penDown = false;

  solutionProvided = false;

  ticks = 0;

  newPuzzle();
}

void
GameLogic::update()
{
  if(largeMarker == 0)
    {
      largeMarker = rage->createSpriteInstance(Rage::MAIN, LARGE_MARKER);
      rage->showSprite(Rage::MAIN, largeMarker, false);
    }

  ticks++;

  if(resultTimer > 0)
    {
      if(--resultTimer == 0)
	{
	  rage->showSprite(Rage::MAIN, largeMarker, false);
	  newPuzzle();
	}

      return;
    }

  if(input->keyPressed(KEY_TOUCH))
    {
      int x, y;

      if(getPenTouch(&x, &y))
	{
	      startX = endX = x;
	      startY = endY = y;
	      
	      rage->selectAnimation(Rage::MAIN, largeMarker, MARKER_1);
	      rage->showSprite(Rage::MAIN, largeMarker, true);
	      rage->moveSpriteAbs(Rage::MAIN, largeMarker, offsetX + x*24 + 4, offsetY + y*24 + 4);
	      penDown = true;
	}
    }
  else if(input->keyReleased(KEY_TOUCH))
    {
      penDown = false;

      if(solutionProvided)
	{
	  // check solution
	  win = field->checkSolution(puzzle, startX, startY,
				     (startX + endX)/2, (startY + endY) / 2,
				     endX, endY);

	  if(win)
	    {
	      wins++;
	    }
	  else
	    {
	      printf("Fail!\n");
	      fails++;
	    }

	  printf("Wins: %d, Fails: %d, Rank: %d\n", wins, fails, wins?ticks/wins/60:0);

	  resultTimer = 60;

	  solutionProvided = false;
	}
      else
	{
	  rage->showSprite(Rage::MAIN, largeMarker, false);
	}
    }

  if(penDown)
    {
      // User moving pen around
      int x, y;

      if(getPenTouch(&x, &y))
	{
	  if(x != endX || y != endY)
	    {
	      endX = x;
	      endY = y;

	      // Is this a correct line?
	      int xdel[17] = {0, 1, 2,  1,  2,  0,  0, -1, -2, -1, -2, -1, -2, 0, 0, 1, 2};
	      int ydel[17] = {0, 0, 0, -1, -2, -1, -2, -1, -2,  0,  0,  1,  2, 1, 2, 1, 2};
	      int anim[17] = {MARKER_1,
			      MARKER_2_HORIZONTAL, MARKER_3_HORIZONTAL,
			      MARKER_2_DOWNLEFT,   MARKER_3_DOWNLEFT,
			      MARKER_2_VERTICAL,   MARKER_3_VERTICAL,
			      MARKER_2_DOWNRIGHT,  MARKER_3_DOWNRIGHT,
			      MARKER_2_HORIZONTAL, MARKER_3_HORIZONTAL,
			      MARKER_2_DOWNLEFT,   MARKER_3_DOWNLEFT,
			      MARKER_2_VERTICAL,   MARKER_3_VERTICAL,
			      MARKER_2_DOWNRIGHT,  MARKER_3_DOWNRIGHT};
	      for(int i = 0;i < 17;i++)
		{
		  if(startX == endX + xdel[i] && startY == endY + ydel[i])
		    {
		      rage->selectAnimation(Rage::MAIN, largeMarker, anim[i]);
		      rage->moveSpriteAbs(Rage::MAIN, largeMarker,
					  (startX < endX ? startX : endX) * 24 + offsetX + 4,
					  (startY < endY ? startY : endY) * 24 + offsetY + 4);

		      if(i > 0 && i%2 == 0)
			solutionProvided = true;
		      else
			solutionProvided = false;
		    }
		}
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
  do
    {
      puzzle = rand() % 50 + 1;
    }
  while(!field->possibleSolutions(puzzle));

  printf("\nPlease find %d somewhere!\n", puzzle);
}

bool
GameLogic::getPenTouch(int *x, int *y)
{
  input->getTouch(x, y);

  if(*x >= offsetX && *y >= offsetY)
    {
      *x -= offsetX;
      *y -= offsetY;

      *x /= 24;
      *y /= 24;

      if(*x >= 0 && *x <= 6 && *y >= 0 && *y <= 6)
	{
	  return true;
	}
    }

  return false;
}
