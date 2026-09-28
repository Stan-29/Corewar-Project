/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** defines includes
*/

#ifndef DEFINES_H_
    #define DEFINES_H_

//return values
    #define ERROR 84
    #define OK 0

//error handling
    #define DEFAULT_ERROR 0
    #define ARGS_NEEDED 1
    #define ROBOT_ERROR 2
    #define MALLOC_FAIL 3
    #define FLAG_ERROR 4
    #define FILE_ERROR 5
    #define DUMP_FLAG_ERROR 6
    #define MAGIC_ERROR 7

//ncurse infos
    #define END_EVENT_CODE -1
    #define PAUSE_START_EVENT 32
    #define NEXT_CYCLE_EVENT 27
    #define SPEED_UP_EVENT 61
    #define SPEED_DOWN_EVENT 45
    #define EXIT_EVENT 113

//flags
    #define DUMP_FLAG "-dump"
    #define PROG_NB_FLAG "-n"
    #define LOAD_ADRESS_FLAG "-a"
    #define NCURSE_FLAG "-v"

//corewar infos
    #define BYTE_READ 1
    #define MAX_ROBOTS_NUMBER 4
    #define WIDTH_DISPLAY 110
    #define NBR_INSTR 16

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

    #define PACKED_ATTR __attribute__((packed))
/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

/* register */
    #define T_REG 1
/* direct  (ld  #1,r1  put 1 into r1) */
    #define T_DIR 2
/* indirect always relative (ld 1,r1 put what's in the address (1+pc) into r1
(4 bytes )) */
    #define T_IND 4
/* LABEL */
    #define T_LAB 8

//size (in bytes)
    #define MAX_ARG_SIZE 4
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

//header
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

//live
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

#endif
