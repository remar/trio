#include "numbers.h"
#include "ids.h"

Rage::TileSetDefinition numbersDef;

numbersDef.version = 1;
numbersDef.tileSetID = NUMBERS;
numbersDef.image.gfx = numbersTiles;
numbersDef.image.gfxLen = numbersTilesLen;
numbersDef.image.pal = numbersPal;
numbersDef.image.palLen = numbersPalLen;
