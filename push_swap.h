#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

int	*ft_atoi(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(int *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(int *),
						void (*del)(int *));
t_list				*ft_lstnew(int *content);
int					ft_lstsize(t_list *lst);

#endif