#include <ncurses.h>
#include "handle_direction.h"
#include "snake_object.h"
#include "user_types.h"

void handle_direction_signal(int signal, coordinates *crd, coordinates_deque *snake)
{
	switch(signal) {
	case key_spacebar:
		crd->x = 0;
		crd->y = 0;
		break;
	case KEY_UP:
		crd->x = 0;
		crd->y = -1;
		break;
	case KEY_DOWN:
		crd->x = 0;
		crd->y = 1;
		break;
	case KEY_LEFT:
		crd->x = -1;
		crd->y = 0;
		break;
	case KEY_RIGHT:
		crd->x = 1;
		crd->y = 0;
		break;
	case ERR:
		move_snake_object(snake, *crd);
		break;
	}
}

