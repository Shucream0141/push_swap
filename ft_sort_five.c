/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:38 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 12:30:14 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_value(t_list *lsta, int *sort)
{
	int	i;

	i = 0;
	while (i < 5 && lsta != NULL)
	{
		sort[i] = lsta->value;
		i++;
		if (lsta->next == NULL)
			break ;
		lsta = lsta->next;
	}
}

t_list	*ft_send_two(t_list *lsta, t_list *lstb, int mid)
{
	t_list	*ptr;
	int		i;

	i = 0;
	while (lsta != NULL)
	{
		if (lsta->value < mid)
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

//これも５個ちゃんとあるか確認必要かも yet function
int	find_third_infive(t_list *lsta, t_list *lstb)
{
	int	*sort;
	int	*return_sort;
	int	i;

	i = 0;
	sort = (int *)malloc(5 * sizeof(int));
	if (sort == NULL)
	{
		ft_freeall(lsta, lstb);
		free_exit(sort, NULL);
		exit(1);
	}
	copy_value(lsta, sort);
	return_sort = rank(sort, 5, 0, 0);
	i = 0;
	while (i < 5 && lsta != NULL)
	{
		if (return_sort[i] == 3)
			break ;
		i++;
		lsta = lsta->next;
	}
	double_free(sort, return_sort);
	return (lsta->value);
}

t_list	*ft_sort_five(t_list *lsta, t_list *lstb)
{
	int		mid;
	t_list	*ptr;

	ptr = lsta;
	while (lsta->next != NULL && lsta->value != 5)
	{
		lsta = lsta->next;
		ptr = lsta;
	}
	lsta = back_to_firstptr(ptr);
	mid = find_third_infive(lsta, lstb);
	lstb = ft_send_two(lsta, lstb, mid);
	lsta = back_to_firstptr(ptr);
	lsta = ft_sort_three(lsta, 1);
	if (lstb->value < lstb->next->value)
		lstb = swapfirst(lstb, -1);
	while (lstb != NULL)
	{
		ptr = lstb->next;
		lsta = push_stack_a_to_b(lstb, lsta, 1);
		lstb = ptr;
	}
	return (lsta);
}
