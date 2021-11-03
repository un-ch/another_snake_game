#ifndef BARRIER_H_SETNRY
#define BARRIER_H_SETNRY

#include "coordinate.h"

#define TRUE	1
#define FALSE	0

int
is_contact_with_barrier(const struct coordinate c,
				const struct coordinate_list *barrier);

void
display_barrier_in_fog_of_war(struct coordinate snake,
							struct coordinate_list *bar);

#endif