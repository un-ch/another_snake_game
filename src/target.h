#ifndef TARGET_H
#define TARGET_H

#include "coordinates.h"

#define TRUE	1
#define FALSE	0

enum { max_target_amount = 100 };

int
is_contact_with_target(const struct coordinates crd,
			struct coordinates_list *target);

void
display_target_in_fog_of_war(struct coordinates snake,
			struct coordinates_list *target);

void
display_target(struct coordinates_list *target);

#endif
