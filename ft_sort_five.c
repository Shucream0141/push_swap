/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:38 by sendo             #+#    #+#             */
/*   Updated: 2023/09/13 13:58:54 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//これも５個ちゃんとあるか確認必要かも yet function
int	find_third_infive(t_list *lsta)
{
	int	*sort;
	int	*return_sort;
	int	i;

	i = 0;
	sort = (int *)malloc(5 * sizeof(int));
	return_sort = (int *)malloc(5 * sizeof(int));
	if (sort == NULL)
		return (-1);
	while (i < 5 && lsta != NULL)
	{
		sort[i] = lsta->value;
		i++;
		if (lsta->next == NULL)
			break ;
		lsta = lsta->next;
	}
	lsta = back_to_Firstptr(lsta);
	return_sort = rank(sort, 5, 0, 0);
	i = 0;
	while (i < 5 && lsta != NULL)
	{
		if (return_sort[i] == 3)
			return (lsta->value);
		i++;
		lsta = lsta->next;
	}
	return (0);
}

t_list	*ft_sort_five(t_list *lsta, t_list *lstb)
{
	int		i;
	int		a;
	t_list	*ptr;

	i = 0;
	a = find_third_infive(lsta);
	while (lsta != NULL)
	{
		if (lsta->value < a)
		{
			ptr = lsta->next;
			lstb = push_stack_a_to_b(lsta, lstb);
			lsta = ptr;
			i++;
			if (i == 2 || ptr == NULL)
				break ;
		}
		else
		{
			if (lsta->next == NULL)
				break ;
			lsta = rotationfirstlast(lsta);
		}
	}
	lsta = ft_sort_three(lsta);
	if (lstb->value < lstb->next->value)
		lstb = swapfirst(lstb);
	while (lstb != NULL)
	{
		ptr = lstb->next;
		lsta = push_stack_a_to_b(lstb, lsta);
		lstb = ptr;
	}
	printstack(lsta);
	return (lsta);
}
