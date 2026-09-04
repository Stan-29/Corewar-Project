##
## EPITECH PROJECT, 2026
## Corewar
## File description:
## Makefile
##

SRC = src/const/error_messages.c 	\
	src/const/flags_tab.c			\
	src/const/op.c 					\
	src/free/free_game_infos.c			\
	src/init/init_robots.c					\
	src/init/init_game_infos.c 				\
	src/parsing/handle_helper.c 	\
	src/parsing/handle_args.c 		\
	src/parsing/handle_files.c 		\
	src/parsing/handle_flags.c 		\
	src/setup-infos/manage_robots_id.c 	\
	src/setup-infos/prepare_infos.c 	\
	src/utils/display_error.c 				\
	src/utils/is_positive_nb.c 				\
	src/utils/is_same_str.c 				\
	src/utils/my_get_nb.c					\
	src/utils/my_strlen.c 					\
	src/utils/my_ustrcat.c 					\
	src/start_game.c				\

NAME = corewar

CC = epiclang


TEST_SRC = tests/unit_tests/init_tests/*.c	\
	tests/unit_tests/parsing_tests/*.c			\
	tests/unit_tests/setup-infos_tests/*.c			\
	tests/unit_tests/utils_tests/*.c		\
	tests/unit_tests/*.c						\
	tests/functionnal_tests/*.c						\

TEST_NAME = tests_results

TEST_CC = gcc

VALGRIND_NAME = valgrind-out.txt

CFLAGS = -I./include -g

OBJ = 	$(SRC:.c=.o)

all : $(OBJ)
	$(CC) -o $(NAME) main.c $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(TEST_NAME)

fclean:	clean
	rm -f $(NAME)
	rm -f $(VALGRIND_NAME)

re:	
	$(MAKE) fclean
	$(MAKE) all

mac_tests_run:	clean
	$(TEST_CC) -o $(TEST_NAME) --coverage -lcriterion \
		$(TEST_SRC) $(SRC) -I./include

gcovrex:	re
	$(MAKE) mac_tests_run
	./$(TEST_NAME)
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"

valgrind: re
	$(MAKE) clean
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=$(VALGRIND_NAME) \
         ./$(NAME) ./champions/bill.cor ./champions/pdd.cor

.PHONY: all clean fclean re mac_tests_run gcovrex valgrind