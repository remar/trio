#include <nds.h>
#include <rage.h>
#include <stdio.h>
#include <time.h>

Rage rage;

int board[7][7];
int numbers[9] = {5, 6, 6, 6, 6, 6, 5, 5, 4};

void initBoard()
{

}

int main(void)
{
  srand(time(0));

  rage.init();

  rage.selectOnTop(Rage::SUB);

  rage.setupBackground(Rage::MAIN, 0, 24, 24);

#include "numbersdef.h"
  rage.loadTileSet(Rage::MAIN, &numbersDef);

#include "markerdef.h"
  rage.loadSprite(Rage::MAIN, &markerDef);

  for(int i = 0;i < 11*8;i++)
    rage.setTile(Rage::MAIN, 0, i%11, i/11, 1, 0);

  for(int y = 0;y < 7;y++)
    for(int x = 0;x < 7;x++)
      {
	  rage.setTile(Rage::MAIN, 0, x+2, y+1, 1, rand()%9+1);
      }

  consoleDemoInit();

  printf("Please find: %d\n", rand()%50+1);

  int marker = rage.createSpriteInstance(Rage::MAIN, 1);

  rage.moveSpriteAbs(Rage::MAIN, marker, 24*2+4, 24*1+4);

  while(1)
    {
      rage.redraw();
    }

  return 0;
}
