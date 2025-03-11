#include "get_next_line.h"

int found_new_line(s_list *list){
	size_t i = 0;
	if(!list) return 0;
	s_list *node = list;
	while(node){
		i = 0;
		while(node->str[i]){
			if(node->str[i]=='\n')return 1;
			i++;
		}
		node = node ->next;
	}
	return 0;
}


char *add_to_buffer(s_list *list){
	if(!list->str) return NULL;
	char *ans = malloc(BUFFER_SIZE + 1);
	
	size_t i = 0;
	while(list->str[i]){
		ans[i] = list->str[i];
		i++;
	}
	ans[i] = '\0';
	return ans;
}

size_t get_len(s_list **list){
	if(!list) return 0;
	s_list *node = *list;
	size_t ans = 0;
	while(node->next){
		ans+=ft_strlen(node->str);
		node = node -> next;
	}
	size_t i = 0;
	while(node->str[i]!='\n'){
		ans++;
		i++;
	}
	return ans;
}

int get_endl_pos(char *str){
	size_t i = 0;
	while(str[i]){
		if(str[i]=='\n') return i;
		i++;
	}
	return 0;
}

char *ft_strdup(char *buff){
	size_t len ;
	size_t i;
	len = (size_t)ft_strlen(buff);

	char *ans = malloc(len +1 );
	if(!ans) return NULL;
	
	i=0;
	while(buff[i]){
		ans[i] = buff[i];	
		i++;
	}
	//buff[i] = '\0';
	return ans;
}

size_t ft_strlen(char *buff){
	
	size_t i;

	i = 0;
	while(buff[i])
		i++;
	
	return (size_t)i;

}
