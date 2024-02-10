#include <ncurses.h>

#include "borders.h"
#include "string.h"
#include "color.h"
#include "game_field.h"

extern game_field g_game_field;

void display_borders_with_game_title(void)
{
	const char *game_title = "Simple Snake Game";
	int border_row_count, border_column_count;

	set_game_field_parametres();

	border_row_count = g_game_field.end_y - g_game_field.begin_y;
	border_column_count = g_game_field.end_x - g_game_field.begin_x;

	WINDOW *game_border = newwin(
		border_row_count,
		border_column_count,
		g_game_field.begin_y,
		g_game_field.begin_x);

	box(game_border, 0, 0);
	wrefresh(game_border);
	set_color(magenta_on_black);

	/* print the game title in the middle of the top border: */
	mvwprintw(stdscr, g_game_field.begin_y, (border_column_count / 2), " %s ", game_title);
	refresh();
}

int is_contact_with_borders(const struct coordinates snake_head)
{
	int result = FALSE;
	int min_screen_pixel_x = g_game_field.begin_x + 2;
	int min_screen_pixel_y = g_game_field.begin_y + 2;
	int max_screen_pixel_x = g_game_field.end_x - 2;
	int max_screen_pixel_y = g_game_field.end_y - 2;
	
	if((snake_head.x < min_screen_pixel_x)
		|| (snake_head.x > max_screen_pixel_x)
		|| (snake_head.y < min_screen_pixel_y)
		|| (snake_head.y > max_screen_pixel_y)) {
		result = TRUE;
	}

	return result;
}
