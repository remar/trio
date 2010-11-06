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
  void newPuzzle();
  bool getPenTouch(int *x, int *y);

  Rage *rage;
  Input *input;

  Field *field;

  int puzzle;
  bool win;

  int resultTimer;

  int wins;
  int fails;

  int ticks;

  int largeMarker;

  bool penDown;

  static const int offsetX = 24*2;
  static const int offsetY = 24*1;

  int startX;
  int startY;
  int endX;
  int endY;

  bool solutionProvided;
};

#endif
