/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef struct mysh_s mysh_t;
struct mysh_s
{
    int y;
    int pipe_state;
    char **env;
    char **path;
    int re;
    int len;
    char *line;
    int d;
    int e;
};

void my_putchar(char c);
int count_word2(char **cmd);
int count_sep(char *path);
int my_put_nbr(int nbr);
int  my_putstr(char  const *str);
int my_strlen(char const *str);
char **str_convertion(char *str);
void free_tab(char **tab);
int check_fonction(char **str);
int check_line(char *line);
char **other_fonct(char **cmd, int nb, char **env);
char *get_str(char **str);
char **modif_env(char **str, int a, char **env);
int check_arg_setenv(char **str, char **env);
int setenv2(char **str, char **env);
int check_arg_unsetenv(char **str, char **env);
int unsetenv2(char **str, char **env);
char *search_path(char **env);
int my_strcmp(char const *s1, char const *s2);
char **create_env(void);
int miniprint(char const *format, ...);
char *my_strncpy(char *dest, char const *src, int n);
int check_command(char **str, mysh_t *mysh, char *line);
char *str_add(char *str, char *path);
int count_cmd(char **str);
char **get_command(char **str, int y);
void command_pip(char **str, mysh_t *mysh, char *line, char *command);
void redirect(char **str, mysh_t *mysh, char *line, char *file);
int multi_command(char **cmd, mysh_t *mysh, char *line);
void redirect_bis(char **str, mysh_t *mysh, char *line, char *file);
void command_basic(char **str, mysh_t *mysh, char *line);
int check_redirect(char **cmd);
char *get_file_redirect(char **cmd);
char *get_old_pwd(char **env);
char **get_command_pipe2(char **cmd, int nb);
int pipe_command_1(int *fd, mysh_t *mysh, char **second_cmd, int i);
int pipe_command_2(int *fd, mysh_t *mysh, char **first_cmd, int i);
char *get_binary(char *str);
int multi_command2(char **cmd, mysh_t *mysh, int *fd, int e);
int pipe_command(char **cmd, mysh_t *mysh, char *line, int i);
pid_t loop2(char *line3, mysh_t *mysh, char **str, char **cmd);
int check_redirect2(char **cmd);
char *get_file_redirect2(char **cmd);
int check_operateur(char **cmd, int nb);