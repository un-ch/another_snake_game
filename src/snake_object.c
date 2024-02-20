#include <stdlib.h>
#include "user_types.h"
#include "snake_object.h"
#include "coordinates.h"
#include "objects.h"

void move_snake_object(coordinates_deque *snake, coordinates direction)
{
	coordinates_doubly_list *temp;

	temp = snake->first;

	if((direction.x == 0) &&
		(direction.y == 0)) {
		while(temp) {
			display_object(snake_obj, temp->coord);
			temp = temp->next;
		}
		return;
	}

	while(temp) {
		display_object(blank_obj, temp->coord);
		temp = temp->next;
	}

	temp = snake->last;
	while(temp->prev) {
		temp->coord.x = temp->prev->coord.x;	
		temp->coord.y = temp->prev->coord.y;	

		temp = temp->prev;
	}

	snake->first->coord.x += direction.x; 
	snake->first->coord.y += direction.y; 

	temp = snake->first;
	while(temp) {
		display_object(snake_obj, temp->coord);	
		temp = temp->next;
	}
}

void add_new_snake_element(coordinates_deque *snake, coordinates crd)
{
	coordinates_doubly_list *temp;

	temp = malloc(sizeof(coordinates_doubly_list));
	temp->coord.x = crd.x;
	temp->coord.y = crd.y;
	temp->prev = snake->last;
	temp->next = NULL;

	if(snake->last == NULL) {
		snake->first = temp;
	} else {
		snake->last->next = temp;
	}
	snake->last = temp;
}
