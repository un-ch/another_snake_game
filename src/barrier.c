#include "barrier.h"
#include "coordinates.h"
#include "objects.h"

int
is_contact_with_barrier(const struct coordinates snake_head,
			const struct coordinates_list *barrier)
{
	const struct coordinates_list *temp = barrier;
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

void
display_barrier_in_fog_of_war(struct coordinates snake_head,
				struct coordinates_list *barrier)
{
	struct coordinates_list *temp = barrier;
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
				show_object_barrier(temp->coord);
		}
		temp = temp->next;
	}
}

void
display_barrier(struct coordinates_list *barrier)
{
	struct coordinates_list *temp = barrier;

	while(temp) {
		show_object_barrier(temp->coord);
		temp = temp->next;
	}
}
