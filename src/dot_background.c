#include <ncurses.h>
#include "user_types.h"
#include "dot_background.h"
#include "color.h"
#include "game_field.h"
#include "objects.h"
#include "coordinates.h"

extern game_field g_game_field;

void display_dot_background(void)
{
	int screen_pixel_x;
	int screen_pixel_y = g_game_field.begin_y + 1;
	coordinates crd;

	for(; screen_pixel_y < (g_game_field.end_y - 1); screen_pixel_y++) {
		for(screen_pixel_x = g_game_field.begin_x + 1; screen_pixel_x < (g_game_field.end_x - 1); screen_pixel_x++) {
			crd.y = screen_pixel_y;
			crd.x = screen_pixel_x;
			display_object(dot_obj, crd);
		}
	}
}

void display_dot_background_in_fog_of_war(const coordinates snake)
{
	int x_max, x_min, y_max, y_min;
	int screen_pixel_y, screen_pixel_x;

	x_max = snake.x + 5;
	x_min = snake.x - 5;
	y_max = snake.y + 5;
	y_min = snake.y - 5;

	screen_pixel_y = y_min;
	screen_pixel_x = x_min;

	for(; screen_pixel_y < (y_max - 1); ++screen_pixel_y) {
		for(screen_pixel_x = x_min; screen_pixel_x < (x_max - 1); ++screen_pixel_x) {
			move(screen_pixel_y, screen_pixel_x);
			addch(symbol_dot);
		}
	}
}
