#include <nds.h>
#include <rage.h>
#include <stdio.h>
#include <time.h>

#include "Input.h"
#include "GameLogic.h"

#include "debug.h"

int numbers[9] = {5, 6, 6, 6, 6, 6, 5, 5, 4};

void setupGfx(Rage *rage)
{
  TRY(rage, rage->init());
  TRY(rage, rage->selectOnTop(Rage::SUB));
  TRY(rage, rage->setupBackground(Rage::MAIN, 0, Rage::BG_MAP_256x256, 24, 24));

  consoleDemoInit();

  printf("Welcome to TrioDS!\n"
	 "(c) Andreas Remar\n"
	 "\n"
	 "Instructions:\n"
	 "To solve a puzzle, locate three\n"
	 "consecutive numbers that are on\n"
	 "a line that can be combined with"
	 "a multiplication and an addition"
	 "or subtraction into the puzzle\n"
	 "number.\n");

#include "numbersdef.h"
  TRY(rage, rage->loadTileSet(Rage::MAIN, &numbersDef));

#include "markerdef.h"
  TRY(rage, rage->loadSprite(Rage::MAIN, &markerDef));
}

int main(void)
{
  Rage rage;

  setupGfx(&rage);

  srand(time(0));

  Input input;
  GameLogic gameLogic(&rage, &input);

  while(1)
    {
      input.getInput();

      gameLogic.update();

      rage.redraw();
    }

  return 0;
}
