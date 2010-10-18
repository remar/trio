#include <nds.h>
#include <rage.h>
#include <stdio.h>
#include <time.h>

#include "Input.h"
#include "GameLogic.h"

int numbers[9] = {5, 6, 6, 6, 6, 6, 5, 5, 4};

void setupGfx(Rage *rage)
{
  rage->init();
  rage->selectOnTop(Rage::SUB);
  rage->setupBackground(Rage::MAIN, 0, 24, 24);

  consoleDemoInit();

#include "numbersdef.h"
  rage->loadTileSet(Rage::MAIN, &numbersDef);

#include "markerdef.h"
  rage->loadSprite(Rage::MAIN, &markerDef);
}

int main(void)
{
  srand(time(0));

  Rage rage;
  setupGfx(&rage);

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
