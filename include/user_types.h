#ifndef USER_TYPES_H
#define USER_TYPES_H

typedef struct coordinates {
	int x;
	int y;
} coordinates; 

typedef struct coordinates_list {
	coordinates coord;
	struct coordinates_list *next;
} coordinates_list;

typedef struct coordinates_doubly_list {
	coordinates coord;
	struct coordinates_doubly_list *next, *prev;
} coordinates_doubly_list;

typedef struct coordinates_deque {
	coordinates_doubly_list *first, *last;
} coordinates_deque;

#endif
