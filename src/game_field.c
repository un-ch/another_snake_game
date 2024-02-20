#include <ncurses.h>
#include "user_types.h"
#include "game_field.h"
#include "objects.h"
#include "borders.h"
#include "color.h"

game_field g_game_field;

void set_screen_parametres(void)
{
	g_game_field.begin_x = getmaxx(stdscr) / 15;
	g_game_field.begin_y = getmaxy(stdscr) / 50;
	g_game_field.end_x = (getmaxx(stdscr) / 3) * 2;
	g_game_field.end_y = getmaxy(stdscr);
}

void clear_screen(void)
{
	int screen_pixel_x;
	int screen_pixel_y = g_game_field.begin_y + 1;
	coordinates crd;

	clear();
	refresh();
	display_borders_with_game_title();

	for(; screen_pixel_y < (g_game_field.end_y - 1); screen_pixel_y++) {
		for(screen_pixel_x = g_game_field.begin_x + 1; screen_pixel_x < (g_game_field.end_x - 1); screen_pixel_x++) {
			crd.y = screen_pixel_y;
			crd.x = screen_pixel_x;
			display_object(blank_obj, crd);
		}
	}
}
