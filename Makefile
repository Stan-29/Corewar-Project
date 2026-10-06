##
## EPITECH PROJECT, 2026
## Corewar
## File description:
## Makefile
##

SRC = src/const/error_messages.c 	\
	src/const/flags_tab.c			\
	src/const/ncurse_events.c		\
	src/const/op.c 					\
	src/free/free_game_infos.c			\
	src/init/init_robots.c					\
	src/init/init_game_infos.c 				\
	src/instr_func/basic_instr.c 		\
	src/instr_func/bin_instr.c 			\
	src/instr_func/store_instr.c 		\
	src/ncurse_handling/basic_events_ncurse.c	\
	src/ncurse_handling/manage_ncurse.c			\
	src/parsing/flags_func.c 			\
	src/parsing/handle_helper.c 		\
	src/parsing/handle_args.c 			\
	src/parsing/handle_files.c 			\
	src/parsing/handle_flags.c 			\
	src/robots_handling/manage_instr.c 			\
	src/robots_handling/manage_robots.c 		\
	src/setup-infos/manage_robots_id.c 		\
	src/setup-infos/manage_load_pos.c 		\
	src/setup-infos/prepare_infos.c 		\
	src/utils/display_error.c 		\
	src/utils/is_positive_nb.c 		\
	src/utils/is_same_str.c 		\
	src/utils/my_get_nb.c			\
	src/utils/my_pow.c				\
	src/utils/my_put_nbr.c			\
	src/utils/my_put_str.c			\
	src/utils/my_putchar.c			\
	src/utils/my_strlen.c 			\
	src/utils/my_ustrcat.c 			\
	src/utils/print_hexa.c 			\
	src/utils/print_modular.c 		\
	src/utils/uc_to_ui.c 			\
	src/utils/ui_to_uc.c 			\
	src/utils/update_pc.c 			\
	src/start_game.c					\
	src/game_loop.c						\
	src/dump_function.c					\

NAME = corewar

CC = epiclang


TEST_SRC = tests/functionnal_tests/*.c					\
	tests/unit_tests/game_loop_tests/*.c			\
	tests/unit_tests/robots_handling_tests/*.c	\
	tests/unit_tests/instr_tests/*.c		\
	tests/unit_tests/ncurse_tests/*.c	\
	tests/unit_tests/init_tests/*.c			\
	tests/unit_tests/parsing_tests/*.c			\
	tests/unit_tests/setup-infos_tests/*.c			\
	tests/unit_tests/utils_tests/*.c					\
	tests/unit_tests/*.c						\

TEST_NAME = tests_results

TEST_CC = gcc


VALGRIND_OUTPUT_NAME = valgrind-out.txt


CFLAGS = -I./include

EXEC_FLAG = -v 50

OBJ = 	$(SRC:.c=.o)

all : $(OBJ)
	$(CC) -o $(NAME) main.c $(OBJ) $(CFLAGS) -lncurses

exec : all
	./corewar $(EXEC_FLAG) -n 1 ./champions/bill.cor -n 234 ./champions/abel.cor -n 2 ./champions/pdd.cor -n 123 ./champions/tyron.cor

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

tests_run:	clean
	$(TEST_CC) -o $(TEST_NAME) --coverage -lcriterion \
	$(TEST_SRC) $(SRC) -I./include -lncurses

gcovrex:	all
	$(MAKE) tests_run
	./$(TEST_NAME)
	gcovr --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"
	gcovr --txt-metric branch --gcov-executable "llvm-cov gcov" \
		--exclude "tests/.*"


all_docker :
	$(CC) -o $(NAME) main.c $(SRC) -I./include -lncurses

re_docker:	
	$(MAKE) fclean
	$(MAKE) all_docker

valgrind: re_docker
	$(MAKE) clean
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=$(VALGRIND_OUTPUT_NAME) \
         ./$(NAME) -dump 0 -n 1 ./champions/bill.cor -n 234 ./champions/abel.cor -n 2 ./champions/pdd.cor -n 123 ./champions/tyron.cor

.SILENT:  
.PHONY: all clean fclean re mac_tests_run gcovrex valgrind