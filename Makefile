##
## EPITECH PROJECT, 2026
## Corewar
## File description:
## Makefile
##

SRC = src/args/handle_helper.c 	\
	src/args/handle_args.c 		\
	src/args/handle_files.c 	\
	src/args/handle_flags.c 	\
	src/const/error_messages.c 		\
	src/const/flags_tab.c			\
	src/const/op.c 					\
	src/init/init_robots.c				\
	src/utils/display_error.c 	\
	src/utils/is_positive_nb.c 	\
	src/utils/is_same_str.c 	\
	src/utils/my_get_nb.c		\
	src/utils/my_strlen.c 		\
	src/start_game.c				\

NAME = corewar

CC = epiclang


TEST_SRC = tests/unit_tests/args_tests/*.c		\
	tests/unit_tests/init_tests/*.c				\
	tests/unit_tests/utils_tests/*.c			\
	tests/unit_tests/*.c						\
	tests/functionnal_tests/*.c					\

TEST_NAME = tests_results

TEST_CC = gcc

all : 
	$(CC) -o $(NAME) main.c $(SRC) -I./include

clean:
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(TEST_NAME)

fclean:	clean
	rm -f $(NAME)

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

.PHONY: all clean fclean re mac_tests_run gcovrex 