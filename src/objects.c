#include <ncurses.h>
#include "user_types.h"
#include "objects.h"
#include "color.h"
#include "display_message.h"

void show_object_target(const coordinates crd)
{
	move(crd.y, crd.x);
	set_color(black_on_white);
	addch(symbol_target);
	refresh();
}

void show_object_snake(const coordinates crd)
{
	move(crd.y, crd.x);
	set_color(red_on_white);
	addch(symbol_snake);
	refresh();
}

void show_object_barrier(const coordinates crd)
{
	move(crd.y, crd.x);
	set_color(black_on_white);
	addch(symbol_barrier);
	refresh();
}

void hide_object(const coordinates crd)
{
	move(crd.y, crd.x);
	set_color(black_on_white);
	addch(symbol_dot);
	refresh();
}

void display_object(enum object obj, const coordinates crd)
{
	move(crd.y, crd.x);
	switch(obj) {
		case target_obj:
			set_color(white_on_black);
			addch(symbol_target);
			break;
		case snake_obj:
			set_color(red_on_black);
			addch(symbol_snake);
			break;
		case barrier_obj:
			set_color(green_on_black);
			addch(symbol_barrier);
			break;
		case blank_obj:
			set_color(black_on_black);
			addch(symbol_blank);
			break;
		case dot_obj:
			set_color(black_on_black);
			addch(symbol_dot);
			break;
		case game_title_obj:
			const char *game_title = " Simple Snake Game ";
			set_color(green_on_black);
			addstr(game_title);
			break;
	}
	refresh();
}
