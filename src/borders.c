#include <ncurses.h>

#include "borders.h"
#include "string.h"
#include "color.h"
#include "screen.h"

extern screen g_screen;

void display_borders_with_game_title(void)
{
	const char *game_title = "Simple Snake Game";
	int border_lines_num, border_column_num;

	set_color(black_on_white);
	set_screen_parametres();

	border_lines_num = g_screen.end_y - g_screen.begin_y;
	border_column_num = g_screen.end_x - g_screen.begin_x;

	WINDOW *game_border = newwin(
		border_lines_num,
		border_column_num,
		g_screen.begin_y,
		g_screen.begin_x);

	box(game_border, 0, 0);
	wrefresh(game_border);

	set_color(magenta_on_black);

	/* print the game title in the middle of the top border: */
	mvwprintw(stdscr, g_screen.begin_y, (border_column_num / 2), " %s ", game_title);
}

int is_contact_with_borders(const struct coordinates snake_head)
{
	int result = FALSE;
	int min_x = 1;
	int min_y = 1;
	int max_x, max_y;

	getmaxyx(stdscr, max_y, max_x);
	max_y -= 2;
	max_x -= 2;

	if((snake_head.x < min_x)
		|| (snake_head.x > max_x)
		|| (snake_head.y < min_y)
		|| (snake_head.y > max_y)) {
		result = TRUE;
	}

	return result;
}
