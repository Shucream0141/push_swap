/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:38 by sendo             #+#    #+#             */
/*   Updated: 2023/09/11 19:20:21 by sendo            ###   ########.fr       */
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
	sort = (int *)malloc(argc * sizeof(int));
	if (sort == NULL)
		return (NULL);
	while (i < argc && lsta != NULL)
	{
		sort[i] = lsta->value;
		lsta = lsta->next;
		i++;
	}
	if (i == argc)
		return_sort = rank(sort, argc, 0, 0);
	i = 0;
	while (i < argc)
	{
		if (return_sort[i] == 3)
			return (lsta->value);
		i++;
		lsta = lsta->next;
	}
	return (0);
}

t_list	*ft_sort_five(t_list *lsta)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	a = find_third_infive(lsta);
	while (lsta != NULL)
	{
		if (a > lsta->value)
		{
			lstb = push_stack_a_to_b(lsta, lstb);
			lsta = lsta->next;
		}
	}
	lsta = back_to_Firstptr(lsta);
	lsta = ft_sort_three(lsta);
	
	while(lstb != NULL)
	{
		lsta = push_stack_a_to_b(lstb, lsta);
		lstb = lstb->next;
	}
	printstack(lstb);
	return lsta;
}
