#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <rage.h>
#include "Input.h"

#include "Field.h"

class GameLogic
{
 public:
  GameLogic(Rage *rage, Input *input);
  void update();

 private:
  Rage *rage;
  Input *input;

  Field *field;

  struct Marker
  {
    int spriteID;

    int x;
    int y;

    bool selected;
  };

  Marker markers[3];
  int currentMarker;
};

#endif
