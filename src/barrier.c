#include "user_types.h"
#include "barrier.h"
#include "coordinates.h"
#include "objects.h"

int is_contact_with_barrier(const coordinates snake_head, const coordinates_list *barrier)
{
	const coordinates_list *temp = barrier;
	int result = FALSE;

	while(temp) {
		if(is_equal_coordinates(snake_head, temp->coord)) {
			result = TRUE;
			break;
		}
		temp = temp->next;
	}

	return result;
}

void display_barrier_in_fog_of_war(coordinates snake_head, coordinates_list *barrier)
{
	coordinates_list *temp = barrier;
	int x_max, x_min, y_max, y_min;

	x_max = snake_head.x + 5;
	x_min = snake_head.x - 5;
	y_max = snake_head.y + 5;
	y_min = snake_head.y - 5;

	while(temp) {
		if((temp->coord.x < x_max) &&
			(temp->coord.y < y_max) &&
			(temp->coord.x > x_min) &&
			(temp->coord.y > y_min)) {
				display_object(barrier_obj, temp->coord);
		}
		temp = temp->next;
	}
}

void display_barrier(coordinates_list *barrier)
{
	coordinates_list *temp = barrier;

	while(temp) {
		display_object(barrier_obj, temp->coord);
		temp = temp->next;
	}
}
