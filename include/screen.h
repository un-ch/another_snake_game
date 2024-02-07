#ifndef SCREEN_H_SENTRY
#define SCREEN_H_SENTRY

typedef struct {
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;
} screen;

void set_screen_parametres(void);
void clear_screen(void);

#endif
