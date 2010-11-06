#include "debug.h"

#include <stdio.h>

void showError(Rage *rage, const char *file, int line)
{
  printf("ERROR!\n"
	 "------\n"
	 "%s:%d\n"
	 "Rage: %s\n", file, line, rage->getErrorString());
}
