#ifndef FIELD_H
#define FIELD_H

#include <rage.h>

class Field
{
 public:
  Field(Rage *rage);
  void drawBoard();
  void randomize();
  bool checkSolution(int x1, int y1, int x2, int y2, int x3, int y3);

 private:
  int board[7][7];
  Rage *rage;
};

#endif
