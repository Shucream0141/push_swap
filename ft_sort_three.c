/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:26:09 by sendo             #+#    #+#             */
/*   Updated: 2023/09/11 15:15:39 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if (lst->next->next == NULL)
// 	return (NULL);これをこの関数の前に入れること。

t_list	*ft_sort_three_split(t_list *lst)
{
	if ((lst->value < lst->next->value)
		&& (lst->next->value > lst->next->next->value))
		return (lst = reverse_rotate(lst));
	else if ((lst->value > lst->next->value)
		&& (lst->next->value < lst->next->next->value))
		return (lst = rotationfirstlast(lst));
	return (NULL);
}

t_list	*ft_sort_three(t_list *lst)
{
	if ((lst->value < lst->next->value)
		&& (lst->next->value < lst->next->next->value))
		return (lst);
	else if ((lst->value > lst->next->value)
		&& (lst->next->value > lst->next->next->value))
	{
		lst = swapfirst(lst);
		return (lst = reverse_rotate(lst));
	}
	if (lst->value < lst->next->next->value)
	{
		if ((lst->value < lst->next->value)
			&& (lst->next->value > lst->next->next->value))
		{
			lst = swapfirst(lst);
			return (lst = rotationfirstlast(lst));
		}
		else if ((lst->value > lst->next->value)
			&& (lst->next->value < lst->next->next->value)) // b a c 2
			return (lst = swapfirst(lst));
	}
	else
		lst = ft_sort_three_split(lst);
	return (lst);
}
// b c a 1
// c a b 2
// a b c
// c b a
// a c b 1
// b a c 2
//順番的にifで分割は必ずしないといけない
