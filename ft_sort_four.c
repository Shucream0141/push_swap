/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:32:08 by sendo             #+#    #+#             */
/*   Updated: 2023/09/25 12:29:02 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_value_four(t_list *lsta, int *sort)
{
	int	i;

	i = 0;
	while (i < 4 && lsta != NULL)
	{
		sort[i] = lsta->value;
		i++;
		if (lsta->next == NULL)
			break ;
		lsta = lsta->next;
	}
}

int	find_third_infour(t_list *lsta, t_list *lstb)
{
	int	*sort;
	int	*return_sort;
	int	i;

	i = 0;
	sort = (int *)malloc(4 * sizeof(int));
	return_sort = (int *)malloc(4 * sizeof(int));
	if (sort == NULL || return_sort == NULL)
	{
		ft_freeall(lsta, lstb);
		free(sort);
		free(return_sort);
		exit(1);
	}
	copy_value_four(lsta, sort);
	lsta = back_to_firstptr(lsta);
	return_sort = rank(sort, 4, 0, 0);
	while (i < 4 && lsta != NULL)
	{
		if (return_sort[i] == 2)
			return (lsta->value);
		i++;
		lsta = lsta->next;
	}
	return (0);
}

t_list	*ft_send_f(t_list *lsta, t_list *lstb, int a)
{
	t_list	*ptr;
	int		i;

	i = 0;
	while (lsta != NULL)
	{
		if (lsta->value <= a)
		{
			ptr = lsta->next;
			lstb = push_stack_a_to_b(lsta, lstb, -1);
			lsta = ptr;
			i++;
			if (i == 2 || ptr == NULL)
				break ;
		}
		else
		{
			if (lsta->next == NULL)
				break ;
			lsta = rotationfirstlast(lsta, 1);
		}
	}
	return (lstb);
}

t_list	*ft_sort_four(t_list *lsta, t_list *lstb)
{
	int		a;
	t_list	*ptr;

	ptr = lsta;
	while (lsta->next != NULL && lsta->value != 4)
	{
		lsta = lsta->next;
		ptr = lsta;
	}
	lsta = back_to_firstptr(ptr);
	a = find_third_infour(lsta, lstb);
	lstb = ft_send_f(lsta, lstb, a);
	lsta = back_to_firstptr(ptr);
	if (lstb->value < lstb->next->value)
		lstb = swapfirst(lstb, -1);
	if (lsta->value > lsta->next->value)
		lsta = swapfirst(lsta, 1);
	while (lstb != NULL)
	{
		ptr = lstb->next;
		lsta = push_stack_a_to_b(lstb, lsta, 1);
		lstb = ptr;
	}
	return (lsta);
}
