#include <ncurses.h>
#include "user_types.h"
#include "borders.h"
#include "string.h"
#include "color.h"
#include "game_field.h"

extern game_field g_game_field;

void display_borders_with_game_title(void)
{
	const char *game_title = "Simple Snake Game";
	const int title_length = string_length(game_title);
	coordinates game_title_position;

	set_color(magenta_on_black);
	set_screen_parametres();

	box(stdscr, 0, 0);
	game_title_position.x =
		(getmaxx(stdscr) - title_length) / 2;
	game_title_position.y = g_game_field.begin_y;

	/* print the game title in the middle of the top border: */
	mvwprintw(stdscr, game_title_position.y, game_title_position.x, " %s ", game_title);
	wrefresh(stdscr);
}

int is_contact_with_borders(const coordinates snake_head)
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
