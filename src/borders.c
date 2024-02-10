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
	int border_row_count, border_column_count;
	coordinates crd;

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

	crd.x = border_column_count / 2;
	crd.y = g_game_field.begin_y;

	display_object(game_title_obj, crd);
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
