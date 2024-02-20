#ifndef GAME_FIELD_H 
#define GAME_FIELD_H

typedef struct game_field {
	int begin_x;
	int begin_y;
	int end_x;
	int end_y;
} game_field;

void set_screen_parametres(void);
void clear_screen(void);

#endif
