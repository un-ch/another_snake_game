#ifndef BORDERS_H_SENTRY
#define BORDERS_H_SENTRY

#include "user_types.h"

#define TRUE	1
#define FALSE	0

enum { false_exit_code = 0 };

void display_borders_with_game_title(void);
int is_contact_with_borders(const coordinates crd);

#endif
