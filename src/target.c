#include <stdlib.h>		/* for free() */
#include "user_types.h"
#include "target.h"
#include "coordinates.h"
#include "objects.h"

int is_contact_with_target(const coordinates crd, coordinates_list *target)
{
	coordinates_list **pp = &target;
	int result = FALSE;

	while(*pp) {
		if(is_equal_coordinates(crd, (*pp)->coord)) {
			coordinates_list *temp = *pp;
			*pp = (*pp)->next;
			free(temp);
			result = TRUE;
			break;
		}
		pp = &(*pp)->next;
	}

	return result;
}

void display_target_in_fog_of_war(coordinates snake, coordinates_list *target)
{
	coordinates_list *temp = target;
	int x_max, x_min, y_max, y_min;

	x_max = snake.x + 5;
	x_min = snake.x - 5;
	y_max = snake.y + 5;
	y_min = snake.y - 5;
	
	while(temp) {
		if((temp->coord.x < x_max) &&
			(temp->coord.y < y_max) &&
			(temp->coord.x > x_min) &&
			(temp->coord.y > y_min)) {
				display_object(target_obj, temp->coord);
		}
		temp = temp->next;
	}
}

void display_target(coordinates_list *target)
{
	coordinates_list *temp = target;

	while(temp) {
		display_object(target_obj, temp->coord);
		temp = temp->next;
	}
}
