#ifndef BORDERS_H
#define BORDERS_H

#include "user_types.h"

#define TRUE 1
#define FALSE 0

enum { false_exit_code = 0 };

void display_borders_with_game_title(void);
int is_contact_with_borders(const coordinates crd);

#endif
