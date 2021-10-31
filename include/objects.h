#ifndef OBJECTS_H_SENTRY
#define OBJECTS_H_SENTRY

enum { symbol_target = '+' };
enum { symbol_snake = '*' };
enum { symbol_barrier_plus = 'x' };
enum { symbol_blank = ' ' };

struct coordinate {
	int x;
	int y;
};

void 
show_object_target(const struct coordinate coord);

void 
show_object_snake(const struct coordinate coord);

void 
show_object_barrier(const struct coordinate coord);

void
hide_object(const struct coordinate coord);

#endif