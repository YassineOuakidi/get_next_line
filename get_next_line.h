#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


#include <stdlib.h>
#include <unistd.h>

typedef struct s_list{
	char *str;
	struct s_list *next;
} s_list ;

char *get_next_line(int fd);
size_t ft_strlen(char *buff);
int found_new_line(s_list *list);
char *ft_strdup(char *buff);
size_t get_len(s_list **list);
int get_endl_pos(char *str);
#endif
