#ifndef ROUND_SETTINGS_H
#define ROUND_SETTINGS_H

#include "user_types.h"

typedef struct round_settings {
	int round_num;
	int current_snake_length;
	int snake_speed;
	int max_barrier_amount;
} round_settings;

void set_objects_another_round(
	coordinates_deque *snake,
	coordinates_list **target,
	coordinates_list **barrier,
	const round_settings rnd_stt,
	coordinates *crd);
void set_settings_initial_round(round_settings *rnd_stt);
void game_settings_increase(round_settings *rnd_stt);
void game_settings_decrease(round_settings *rnd_stt);
void update_after_contact_with_target(
	round_settings *rnd_stt,
	coordinates_deque *snake,
	coordinates crd);

#endif
