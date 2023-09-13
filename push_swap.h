/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:58 by sendo             #+#    #+#             */
/*   Updated: 2023/09/12 12:35:09 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*swapfirst(t_list *lst);
t_list				*swap_a_and_b(t_list *lsta, t_list *lstb);
t_list				*rotationfirstlast(t_list *lst);
t_list				*rotate_a_and_b(t_list *lsta, t_list *lstb);
t_list				*reverse_rotate(t_list *lsta);
t_list				*push_stack_a_to_b(t_list *lsta, t_list *lstb);
t_list				*addlst(int num, t_list *st);
t_list				*back_to_Firstptr(t_list *lst);
t_list				*back_to_Firstptr(t_list *lst);

void				printstack(t_list *lst);
int					*rank(int *lst, int arg_num, int max, int num);

t_list				*ft_sort_three(t_list *lst);
t_list				*ft_sort_five(t_list *lsta, t_list *lstb);

#endif

/*
sa (swap a): Swap the first 2 elements at the top of stack a.//Done
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.//Done
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.							//Done
pa (push a): Take the first element at the top of b and put it at the top of a.//Done
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.//Done
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.//Done
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.??Done
The first element becomes the last one.
rr : ra and rb at the same time. //Done
rra (reverse rotate a): Shift down all elements of stack a by 1. //done
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. //done
The last element becomes the first one.
rrr : rra and rrb at the same time. //Yet
*/