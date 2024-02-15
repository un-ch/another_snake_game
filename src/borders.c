#include <ncurses.h>
#include "user_types.h"
#include "borders.h"
#include "string.h"
#include "color.h"
#include "game_field.h"
#include "objects.h"
#include "coordinates.h"

extern game_field g_game_field;

void display_borders_with_game_title(void)
{
	const char *game_title = "Simple Snake Game";
	int border_row_count, border_column_count;
	int game_title_string_length = string_length(game_title);
	coordinates game_title_position;

	set_game_field_parametres();

	border_row_count = g_game_field.end_y - g_game_field.begin_y;
	border_column_count = g_game_field.end_x - g_game_field.begin_x;

	WINDOW *game_border = newwin(
		border_row_count,
		border_column_count,
		g_game_field.begin_y,
		g_game_field.begin_x);

	box(game_border, 0, 0);

	/* set the game title position on the top border: */
	game_title_position.x = (g_game_field.end_x - game_title_string_length - g_game_field.begin_x) / 2;
	game_title_position.y = g_game_field.begin_y;

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attrset(COLOR_PAIR(green_on_black));
    wbkgd(game_border, COLOR_PAIR(1));
	mvwprintw(game_border, game_title_position.y, game_title_position.x, " %s ", game_title);
	wrefresh(game_border);
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
