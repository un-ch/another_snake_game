#ifndef TARGET_H
#define TARGET_H

#include "user_types.h"
#include "coordinates.h"

#define TRUE	1
#define FALSE	0

enum { max_target_amount = 10 };

int is_contact_with_target(const coordinates crd, coordinates_list *target);
void display_target_in_fog_of_war(coordinates snake, coordinates_list *target);
void display_target(coordinates_list *target);

#endif
