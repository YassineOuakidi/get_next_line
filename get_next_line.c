#include "get_next_line.h"
#include <stdio.h>


char *create_ans(s_list **list){
	s_list *node = *list;
	size_t j , i , len ;
	len = get_len(list);
	char *ans = malloc(len + 2);
	if(!ans) return NULL;
	j=0;
	while(node){
		i = 0;
		while(node->str[i]){
			if(node->str[i]=='\n'){
				ans[j++]= '\n';
				ans[j]= '\0';
				return ans;
			} else {
				ans[j] = node->str[i];
				i++;
				j++;
			}
		}
		node = node->next;
	}
	ans[j] = '\0';
	return ans;

}


static void create_list(s_list **list , int fd){
	char *buff = malloc(BUFFER_SIZE + 1);
	if(!buff)
		return ;
	int n = BUFFER_SIZE;
	s_list *tail = *list;
	if(!tail) *list =NULL;
	while(!found_new_line(*list) && n==BUFFER_SIZE ){
		s_list *new_node = malloc(sizeof(s_list));
		if(!new_node){
			free(buff);
			return ;
		}

		n = read(fd , buff , BUFFER_SIZE);
		if(n<=0) {
			*list = NULL;
			free(new_node);
			break;
			
		}
		buff[n] = '\0';
		new_node->str = ft_strdup(buff);
		if(!new_node->str){
			free(new_node);
			break;
		}
		new_node->next = NULL;
		if(!(*list)){
			(*list) = new_node;
			tail = *list;
		} else {
			tail->next = new_node; 
			tail = tail->next;
		}
	}
	free(buff);
}
void free_list(s_list *list){
	list = list->next;
	while(list){
        	s_list *tmp = list;
		if(tmp->str) free(tmp->str);
		list = list->next;
        	free(tmp);
    	}
}

static void polish_list(s_list **list){
	if(!list || !*list) return ;
	s_list *last_node = *list;

	while(last_node->next)
		last_node = last_node->next;
	
	size_t i ; 
	i =get_endl_pos(last_node->str)+1;
	size_t j = 0;

	char *reminder = malloc(ft_strlen(last_node->str) - get_endl_pos(last_node->str) + 1);
	
	if(!reminder)
		return;

	while(last_node->str[i]){
		reminder[j] = last_node->str[i];
		j++;i++;
	}
	reminder[j] = '\0';
	s_list *head = malloc(sizeof(s_list));
	
	head->str = ft_strdup(reminder);
	head->next = NULL;
	
	*list = head;

	free_list(*list);
	free(reminder);
}


char *get_next_line(int fd){
	static s_list *list = NULL;

	if(fd<0 || read(fd , NULL , 0)<0)
		return NULL;
	create_list(&list , fd);
	if(!list)
		return NULL;
	char *ans ;
	ans = create_ans(&list);
	
	polish_list(&list);
	return ans;
}
