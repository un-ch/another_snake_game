#ifndef ROUND_SETTINGS_H_SENTRY
#define ROUND_SETTINGS_H_SENTRY

#include "coordinates.h"

struct round_settings {
	int round_num;
	int current_snake_length;
	int snake_speed;
	int max_barrier_amount;
};

void
set_objects_another_round(struct coordinates_deque *snake,
						struct coordinates_list **target,
						struct coordinates_list **barrier,
						const struct round_settings rnd_stt,
						struct coordinates *crd);

void
set_settings_initial_round(struct round_settings *rnd_stt);

void
game_settings_increase(struct round_settings *rnd_stt);

void
game_settings_decrease(struct round_settings *rnd_stt);

void
update_after_contact_with_target(struct round_settings *rnd_stt,
								struct coordinates_deque *snake,
								struct coordinates crd);

#endif
