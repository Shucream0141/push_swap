/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:58 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 16:09:20 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
// typedef struct s_list
// {
// 	void			*content;
// 	int					value;
// 	struct s_list		*next;
// 	struct s_list		*prev;
// }						t_list;

t_list					*swapfirst(t_list *lst, int flag);
t_list					*swap_a_and_b(t_list *lsta, t_list *lstb);
t_list					*rotationfirstlast(t_list *lst, int flag);
t_list					*rotate_a_and_b(t_list *lsta, t_list *lstb);
t_list					*reverse_rotate(t_list *lsta, int flag);
t_list					*push_stack_a_to_b(t_list *lsta, t_list *lstb,
							int flag);
t_list					*addlst(int num, t_list *st);
t_list					*back_to_firstptr(t_list *lst);
t_list					*first_to_lastptr(t_list *lst);

t_list					*ft_send_two(t_list *lsta, t_list *lstb, int mid);
void					printstack(t_list *lst);

t_list					*ft_sort_three(t_list *lst, int flag);
t_list					*ft_sort_five(t_list *lsta, t_list *lstb);
t_list					*ft_sort_four(t_list *lsta, t_list *lstb);
t_list					*ft_sort_six(t_list *lsta, t_list *lstb);
t_list					*ft_algorithm(t_list *lsta, t_list *lstb, int argc);
t_list					*ft_algorithm_seven(t_list *lsta, t_list *lstb,
							int argc);

void					*ft_freeall(t_list *lsta, t_list *lstb);
void					double_free(int *sort, int *return_sort);
void					free_exit(int *sorted, int *lst);
void					ft_exit_print(int *sort);
int						*rank(int *lst, int arg_num, int max, int num);
int						ft_advanced_atoi(const char *str, int *sort);
int						ft_isdouble_error(int *sort, int argc);
int						ft_is_sorted(t_list *lsta, t_list *lstb);
t_list					*ft_deal_args(int argc, char **argv);

int						ft_printf(const char *str, ...);
#endif
