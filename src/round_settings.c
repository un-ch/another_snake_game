#include <stddef.h> /* for NULL */
#include <ncurses.h> /* for getmaxyx() */
#include "user_types.h"
#include "borders.h"
#include "round_settings.h"
#include "coordinates.h"
#include "display_message.h"
#include "snake_object.h"
#include "target.h"
#include "game_field.h"
#include "dot_background.h"

void set_objects_another_round(
		coordinates_deque *snake,
		coordinates_list **target,
		coordinates_list **barrier,
		const round_settings rnd_stt,
		coordinates *crd)
{
	coordinates snake_head;

	if(*target) {
		delete_coordinate_list(target);
		delete_coordinate_list(barrier);
		delete_coordinate_doubly_list(&(snake->first));
	}

	snake->first = NULL;
	snake->last = NULL;
	*barrier = NULL;
	*target = NULL;
	crd->x = 0;
	crd->y = 0;

	clear_screen();
	display_borders_with_game_title();
	display_round_number(rnd_stt.round_num);
	set_random_coordinates(&snake_head);
	add_new_snake_element(snake, snake_head);
	(*barrier) = fill_in_coordinates_random(rnd_stt.max_barrier_amount, snake_head);
	(*target) = fill_in_coordinates_random(max_target_amount, snake_head);
	display_dot_background();
}

void set_settings_initial_round(round_settings *rnd_stt)
{
	int max_screen_value_x, max_screen_value_y;
	int barrier_amount;

	getmaxyx(stdscr, max_screen_value_y, max_screen_value_x);
	barrier_amount = max_screen_value_y + max_screen_value_x;
	rnd_stt->round_num = 1;
	rnd_stt->current_snake_length = 1;
	rnd_stt->snake_speed = 200;
	rnd_stt->max_barrier_amount = barrier_amount;
}

void game_settings_increase(round_settings *rnd_stt)
{
	rnd_stt->round_num += 1;
	rnd_stt->current_snake_length = 1;
	rnd_stt->snake_speed -= 50;
	rnd_stt->max_barrier_amount += 150;
}

void game_settings_decrease(round_settings *rnd_stt)
{
	rnd_stt->round_num -= 1;
	rnd_stt->current_snake_length = 1;
	rnd_stt->snake_speed -= 5;
	rnd_stt->max_barrier_amount -= 150;
}

void update_after_contact_with_target(
	round_settings *rnd_stt,
	coordinates_deque *snake,
	coordinates crd)
{
	coordinates temp;

	temp.x = snake->last->coord.x - crd.x;
	temp.y = snake->last->coord.y - crd.y;

	rnd_stt->current_snake_length += 1;
	add_new_snake_element(snake, temp);
}
