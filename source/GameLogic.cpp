#include "GameLogic.h"
#include "ids.h"
#include <stdio.h>

GameLogic::GameLogic(Rage *rage, Input *input)
  : rage(rage), input(input)
{
  field = new Field(rage);

  field->randomize();

  markers[0].selected = markers[1].selected = markers[2].selected = false;
  currentMarker = 0;
}

void
GameLogic::update()
{
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
	      bool win = field->checkSolution(markers[0].x, markers[0].y,
					      markers[1].x, markers[1].y,
					      markers[2].x, markers[2].y);

	      if(win)
		printf("Correct!\n");
	      else
		printf("Fail!\n");

	      for(int i = 0;i < 3;i++)
		{
		  rage->removeSpriteInstance(Rage::MAIN, markers[i].spriteID);
		  markers[i].selected = false;
		}
	    }
	}
    }  

  if(input->keyPressed(KEY_A))
    {
      field->randomize();
    }
}
