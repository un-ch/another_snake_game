#include <ncurses.h>
#include <stdlib.h> /* for malloc */
#include "user_types.h"
#include "coordinates.h"
#include "get_random_number.h"
#include "screen.h"

extern screen g_screen;

void set_random_coordinates(coordinates *crd)
{
	int min_screen_pixel_x = g_screen.begin_x + 1;
	int min_screen_pixel_y = g_screen.begin_y + 1;
	int max_screen_pixel_x = g_screen.end_x - 11;
	int max_screen_pixel_y = g_screen.end_y - 2;

	/* we assume that there is no opportunity to display symbols
	 * in (max_screen_pixel_y, max_screen_pixel_x) screen coordinates;
	 * borders around the game field holds the (max_screen_pixel_y-1, max_screen_pixel_x-1)
	 * coordinates;
	 * so, objects inside the borders should have next maximum
	 * values:
	 */

	crd->x = get_random_int_number(min_screen_pixel_x, max_screen_pixel_x);
	crd->y = get_random_int_number(min_screen_pixel_y, max_screen_pixel_y);
}

int is_equal_coordinates(const coordinates crd, const coordinates crd_pattern)
{
	int result = TRUE;

	if((crd.x != crd_pattern.x) ||
		(crd.y != crd_pattern.y)) {

		result = FALSE;
	}

	return result;
}

coordinates_list *fill_in_coordinates_random(
	const int max_iterator,
	const coordinates snake_head)
{
	coordinates_list *first = NULL, *temp;
	int i = 0;

	for(; i < max_iterator; i++) {
		temp = malloc(sizeof(coordinates_list));

		do {
			set_random_coordinates(&temp->coord);
		} while (is_equal_coordinates(temp->coord, snake_head));

		temp->next = first;
		first = temp;
	}

	return first;
}

void delete_coordinate_list(coordinates_list **list)
{
	while(*list) {
		coordinates_list *temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}

void delete_coordinate_doubly_list(coordinates_doubly_list **list)
{
	while(*list) {
		coordinates_doubly_list *temp = *list;
		*list = (*list)->next;
		free(temp);
	}
}
