##
## EPITECH PROJECT, 2026
## Corewar
## File description:
## Makefile
##

SRC = src/args/handle_helper.c 	\
	src/const/error_messages.c 			\
	src/const/op.c 						\
	src/utils/display_error.c 		\
	src/utils/is_same_str.c 		\
	src/utils/my_strlen.c 			\
	src/start_game.c			\

NAME = corewar

CC = epiclang


TEST_SRC = tests/unit_tests/args_tests/test_handle_helper.c 		\
	tests/unit_tests/utils_tests/test_my_strlen.c 			\
	tests/unit_tests/utils_tests/test_is_same_str.c 		\
	tests/unit_tests/utils_tests/test_display_error.c 		\
	tests/unit_tests/test_display_instr.c 		\
	tests/functionnal_tests/test_start_game.c 			\

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