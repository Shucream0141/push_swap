/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shucream <shucream@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:30:29 by sendo             #+#    #+#             */
/*   Updated: 2023/09/23 18:24:16 by shucream         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotationfirstlast(t_list *lst, int flag)
{
	t_list	*first_to_last;
	t_list	*second_to_first;

	if (lst == NULL)
		return (NULL);
	first_to_last = lst;
	second_to_first = lst->next;
	second_to_first->prev = NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = first_to_last;
	first_to_last->next = NULL;
	first_to_last->prev = lst;
	if(flag == 1)
		printf("ra\n");
	else if(flag == -1)
		printf("rb\n");
	return (second_to_first);
}

t_list	*swapfirst(t_list *lst,int flag)
{
	t_list	*bef_first;
	t_list	*third;
	t_list	*aft_first;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	bef_first = lst;
	aft_first = lst->next;
	third = lst->next->next;

	bef_first->next = third;
	bef_first->prev = aft_first;
	aft_first->prev = NULL;
	aft_first->next = bef_first;
	if(third != NULL)
		third->prev = bef_first;
	if(flag == 1)
		printf("sa\n");
	else if(flag == -1)
		printf("sb\n");

	return (aft_first);
}

t_list	*rotate_a_and_b(t_list *lsta, t_list *lstb)
{
	lsta = rotationfirstlast(lsta,1);
	lstb = rotationfirstlast(lstb,-1);
	printf("rr\n");
	return (lsta);
}

t_list	*swap_a_and_b(t_list *lsta, t_list *lstb)
{
	lsta = swapfirst(lsta,1);
	lstb = swapfirst(lstb,-1);
	printf("ss\n");
	return (lsta);
}

t_list	*reverse_rotate(t_list *lsta,int flag)
{
	t_list	*first_to_second;
	t_list	*last_to_first;

	if (lsta == NULL || lsta->next == NULL)
		return (NULL);
	first_to_second = lsta;
	while (lsta->next != NULL)
	{
		lsta = lsta->next;
	}
	last_to_first = lsta;
	last_to_first->prev->next = NULL;
	first_to_second->prev = last_to_first;
	last_to_first->next = first_to_second;
	last_to_first->prev = NULL;
	if(flag == 1)
		printf("rra\n");
	else if(flag == -1)
		printf("rrb\n");
	return (last_to_first);
}

t_list	*rra(t_list *lsta, t_list *lstb)
{
	lsta = reverse_rotate(lsta,1);
	lstb = reverse_rotate(lstb,-1);
	printf("rrr\n");
	return (lsta);
}
//変更する部分は、１番目の場所を保持して、prevに最後のやつをわり当てる。
//次に先頭のnextに１番目のポインタを指定する。
//返すのは新しい先頭の位置だから、ptr->next != NULLな最初０最後１のポインタを保持
//最初９最後０のポインタのnextをNULLにする。
