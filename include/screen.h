#ifndef SCREEN_H
#define SCREEN_H

typedef struct screen {
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;
} screen;

void set_screen_parametres(void);
void clear_screen(void);

#endif
