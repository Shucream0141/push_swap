/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:32:08 by sendo             #+#    #+#             */
/*   Updated: 2023/09/18 12:38:48 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_third_infour(t_list *lsta)
{
	int	*sort;
	int	*return_sort;
	int	i;

	i = 0;
	sort = (int *)malloc(4 * sizeof(int));
	return_sort = (int *)malloc(4 * sizeof(int));
	if (sort == NULL)
		return (-1);
	while (i < 4 && lsta != NULL)
	{
		sort[i] = lsta->value;
		i++;
		if (lsta->next == NULL)
			break ;
		lsta = lsta->next;
	}
	lsta = back_to_Firstptr(lsta);
	return_sort = rank(sort, i, 0, 0);
	i = 0;
	while (i < 4 && lsta != NULL)
	{
		if (return_sort[i] == 2)
			return (lsta->value);
		i++;
		lsta = lsta->next;
	}
	return (0);
}

t_list *ft_sort_four(t_list *lsta, t_list *lstb,int flag)
{
	int i;
	int a;

	t_list *ptr;
	i = 0;
	a = find_third_infour(lsta);
	while(lsta != NULL)
	{
		if(lsta->value <= a)
		{
			ptr = lsta->next;
			lstb = push_stack_a_to_b(lsta,lstb,flag*(-1));
			lsta = ptr;
			i++;
			if(i == 2 || ptr == NULL)
				break;
		}
		else
		{
			if (lsta->next == NULL)
				break ;
			lsta = rotationfirstlast(lsta,flag);
		}
	}
	if (lstb->value < lstb->next->value)
		lstb = swapfirst(lstb,flag*(-1));
	if (lsta->value > lsta->next->value)
		lsta = swapfirst(lsta,flag);
	while (lstb != NULL)
	{
		ptr = lstb->next;
		lsta = push_stack_a_to_b(lstb, lsta,flag);
		lstb = ptr;
	}
	return (lsta);
}
