#include "Input.h"

Input::Input()
{

}

void
Input::getInput()
{
  // read in input changes into the variables
  scanKeys();

  keys_held = keysHeld();
  keys_down = keysDown();
  keys_up = keysUp();

  touchRead(&touchData);
}

bool
Input::keyPressed(uint32 key)
{
  return keys_down & key;
}

bool
Input::keyReleased(uint32 key)
{
  return keys_up & key;
}

bool
Input::keyHeld(uint32 key)
{
  return keys_held & key;
}

void
Input::getTouch(int *x, int *y)
{
  *x = touchData.px;
  *y = touchData.py;
}
