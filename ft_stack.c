/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:01 by sendo             #+#    #+#             */
/*   Updated: 2023/10/03 20:42:06 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addlst(int num, t_list *st)
{
	t_list	*ptr;

	ptr = st;
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
			return (NULL);
		st->next->value = num;
		st->next->next = NULL;
		st->next->prev = ptr;
		return (st->next);
	}
}

t_list	*push_stack_a_to_b(t_list *lsta, t_list *lstb, int flag)
{
	if (flag == 1)
		ft_printf("pa\n");
	else if (flag == -1)
		ft_printf("pb\n");
	if (lsta == NULL)
		return (NULL);
	if (lstb == NULL)
	{
		lsta->next->prev = NULL;
		lsta->next = NULL;
		lsta->prev = NULL;
		return (lsta);
	}
	else
	{
		if (lsta->next != NULL)
			lsta->next->prev = NULL;
		lsta->prev = NULL;
		lsta->next = lstb;
		lstb->prev = lsta;
		return (lsta);
	}
}
//こっちではlstbの先頭を示すに徹して、送った方が元の次のやつを保存しておけばいい