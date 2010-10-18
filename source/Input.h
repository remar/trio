#ifndef INPUT_H
#define INPUT_H

#include <nds.h>

class Input
{
 public:
  Input();
  void getInput();
  bool keyPressed(uint32 key);
  bool keyReleased(uint32 key);
  bool keyHeld(uint32 key);
  void getTouch(int *x, int *y);
  
 private:
  uint32 keys_held;
  uint32 keys_down;
  uint32 keys_up;

  touchPosition touchData;
};

#endif
