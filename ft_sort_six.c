/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:16:45 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 13:22:13 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_send_half(t_list *lsta, t_list *lstb)
{
	int		i;
	t_list	*ptr;

	i = 0;
	while (lsta != NULL)
	{
		if (lsta->value <= 3)
		{
			ptr = lsta->next;
			lstb = push_stack_a_to_b(lsta, lstb, -1);
			lsta = ptr;
			i++;
			if (i == 3 || ptr == NULL)
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

t_list	*ft_sort_six(t_list *lsta, t_list *lstb)
{
	t_list	*ptr;

	while (lsta->next != NULL && lsta->value != 6)
		lsta = lsta->next;
	lsta = back_to_firstptr(lsta);
	lstb = ft_send_half(lsta, lstb);
	lsta = back_to_firstptr(lsta);
	lsta = ft_sort_three(lsta, 1);
	lstb = ft_sort_three(lstb, -1);
	lstb = swapfirst(lstb, -1);
	lstb = reverse_rotate(lstb, -1);
	while (lstb != NULL)
	{
		ptr = lstb->next;
		lsta = push_stack_a_to_b(lstb, lsta, 1);
		lstb = ptr;
	}
	return (lsta);
}
