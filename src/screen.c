#include	<ncurses.h>

#include "screen.h"
#include "objects.h"
#include "borders.h"
#include "color.h"

screen g_screen;

void set_screen_parametres(void)
{
	g_screen.begin_x = getmaxx(stdscr) / 15;
	g_screen.begin_y = getmaxy(stdscr) / 50;
	g_screen.end_x = (getmaxx(stdscr) / 3) * 2;
	g_screen.end_y = getmaxy(stdscr);
}

void clear_screen(void)
{
	int screen_pixel_x;
	int screen_pixel_y = g_screen.begin_y + 1;
	struct coordinates crd;

	clear();
	refresh();
	display_borders_with_game_title();

	for(; screen_pixel_y < (g_screen.end_y - 1); screen_pixel_y++) {
		for(screen_pixel_x = g_screen.begin_x + 1; screen_pixel_x < (g_screen.end_x - 1); screen_pixel_x++) {
			crd.y = screen_pixel_y;
			crd.x = screen_pixel_x;
			display_object(blank_obj, crd);
		}
	}
}
