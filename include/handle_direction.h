#ifndef HANDLE_DIRECTION_H
#define HANDLE_DIRECTION_H

#include "user_types.h"

enum { key_spacebar = ' ' };

void handle_direction_signal(
	int signal,
	coordinates *crd,
	coordinates_deque *snake);

#endif
