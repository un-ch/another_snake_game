#ifndef BARRIER_H
#define BARRIER_H

#include "user_types.h"

#define TRUE 1
#define FALSE 0

int is_contact_with_barrier(
	const coordinates snake_head,
	const coordinates_list *barrier);

void display_barrier_in_fog_of_war(
	coordinates snake_head,
	coordinates_list *barrier);

void display_barrier(coordinates_list *barrier);

#endif
