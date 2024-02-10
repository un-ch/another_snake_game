#ifndef END_PROGRAM_H
#define END_PROGRAM_H

enum { exit_success_code = 0 };

enum end_type {
	quit	= 1,
	win		= 2
};

void end(enum end_type how);

#endif
