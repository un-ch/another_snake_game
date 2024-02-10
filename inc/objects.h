#ifndef OBJECTS_H
#define OBJECTS_H

#include "user_types.h"

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

void show_object_target(const coordinates crd);
void show_object_snake(const coordinates crd);
void show_object_barrier(const coordinates crd);
void hide_object(const coordinates crd);
void display_object(enum object obj, const coordinates crd);

#endif
