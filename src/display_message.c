#include <ncurses.h>
#include <unistd.h>
#include "user_types.h"
#include "display_message.h"
#include "string.h"
#include "game_field.h"
#include "color.h"

extern game_field g_game_field;

void display_message_center(const char *string)
{
	int max_screen_value_y, max_screen_value_x;
	int string_len;

	clear_screen();
	getmaxyx(stdscr, max_screen_value_y, max_screen_value_x);
	string_len = string_length(string);
	move((max_screen_value_y / 2), (max_screen_value_x - string_len - 1) / 2);
	set_color(black_on_white);
	addstr(string);
	refresh();
	sleep(2);
}

void display_round_number(const int number)
{
	const char *round_message = "Round";
	const int string_len = string_length(round_message);
	coordinates round_message_position;

	round_message_position.x =
		(g_game_field.end_x - string_len - g_game_field.begin_x) / 2;
	round_message_position.y = g_game_field.end_y / 2;

	set_color(green_on_black);

	mvwprintw(stdscr, round_message_position.y, round_message_position.x, "%s %d", round_message, number);
	refresh();
	sleep(2);
}
