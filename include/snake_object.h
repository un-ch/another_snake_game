#ifndef SNAKE_OBJECT_H
#define SNAKE_OBJECT_H

#include "user_types.h"

enum { max_snake_length = 5 };

void move_snake_object(coordinates_deque *snake, coordinates direction);
void add_new_snake_element(coordinates_deque *snake, coordinates crd);

#endif
