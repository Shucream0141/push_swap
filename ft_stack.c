/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:01 by sendo             #+#    #+#             */
/*   Updated: 2023/09/13 13:55:36 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addlst(int num, t_list *st)
{
	t_list *ptr = st; //これを使ってallfreeする。
	if (st == NULL)
	{
		st = malloc(sizeof(t_list));
		if (st == NULL)
			return (NULL);
		st->value = num;
		st->next = NULL;
		st->prev = NULL;
		return (st);
	}
	else
	{
		st->next = malloc(sizeof(t_list));
		if (st == NULL)
			return (NULL); //ここでptrを使って全部freeしていく予定
		st->next->value = num;
		st->next->next = NULL;
		st->next->prev = ptr;
		return (st->next);
	}
}

t_list	*push_stack_a_to_b(t_list *lsta, t_list *lstb)
{
	printf("now...push\n");
	if (lsta == NULL)
		return (NULL);
	if (lstb == NULL)
	{
		lsta->next->prev = NULL;
		lsta->next = NULL;
		lsta->prev = NULL;
		return (lsta); //aからbに渡した先頭のポインタを返す
	}
	else
	{
		if(lsta->next != NULL)
			lsta->next->prev = NULL;
		lsta->prev = NULL;
		lsta->next = lstb;
		lstb->prev = lsta;
		return (lsta);//aからbに渡した先頭のポインタを返す
	}
}//こっちではlstbの先頭を示すに徹して、送った方が元の次のやつを保存しておけばいい