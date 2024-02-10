#ifndef OBJECTS_H
#define OBJECTS_H

#include "coordinates.h"

enum {
	symbol_target = '+',
	symbol_snake = '+',
	symbol_barrier = '#',
	symbol_blank = ' ',
	symbol_dot = '.'
};

enum object {
	target_obj,
	snake_obj,
	barrier_obj,
	blank_obj,
	dot_obj,
	game_title_obj
};

void show_object_target(const struct coordinates crd);

void show_object_snake(const struct coordinates crd);

void show_object_barrier(const struct coordinates crd);

void hide_object(const struct coordinates crd);

void display_object(enum object obj, const struct coordinates crd);

#endif
