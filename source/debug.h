#ifndef DEBUG_H
#define DEBUG_H

#include "rage.h"

#define TRY(r, x) {if(RAGE_FAILED(x)) showError(r, __FILE__, __LINE__);}

void showError(Rage *rage, const char *file, int line);

#endif
