#ifndef COORDINATES_H
#define COORDINATES_H

#include "user_types.h"

void set_random_coordinates(coordinates *crd);
int is_equal_coordinates(const coordinates crd, const coordinates crd_pattern);
coordinates_list *fill_in_coordinates_random(const int max_iterator, const coordinates crd);
void delete_coordinate_list(coordinates_list **list);
void delete_coordinate_doubly_list(coordinates_doubly_list **list);

#endif
