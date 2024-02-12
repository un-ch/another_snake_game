CC=	gcc
CFLAGS=	-Wall -I

# directories definitions:
BUILD_DIR=	build
INCLUDE_DIR=	inc
SRC_DIR=	src

SRC_FILES = $(filter-out $(SRC_DIR)/another_snake_game.c, $(wildcard $(SRC_DIR)/*.c))

# set object files to the build directory:
OBJECT_FILES=	$(subst \
	$(SRC_DIR), \
	$(BUILD_DIR), \
	$(SRC_FILES:.c=.o))

HEADER_FILES=	$(wildcard $(INCLUDE_DIR)/*.h)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/%.h
	@$(CC) $(CFLAGS)$(INCLUDE_DIR) -c $< -o $@

# targets:
another_snake_game: $(SRC_DIR)/another_snake_game.c -lncurses \
	$(OBJECT_FILES)
	@$(CC) $(CFLAGS) $(INCLUDE_DIR) $^ -o $(BUILD_DIR)/$@

.PHONY: run
run: another_snake_game
	@./$(BUILD_DIR)/another_snake_game

.PHONY: clean
clean:
	@rm -f	$(BUILD_DIR)/*.o $(BUILD_DIR)/another_snake_game

.PHONY: tags
tags:
	@ctags inc/*.h src/*.c
