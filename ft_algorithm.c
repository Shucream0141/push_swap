/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shucream <shucream@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:57 by sendo             #+#    #+#             */
/*   Updated: 2023/09/23 15:00:50 by shucream         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_push1(t_list *lsta, t_list *lstb, int flag)
{
	int		breakman;
	t_list	*ptr;

	breakman = 0;
	while (1)
	{
		if (lstb == NULL)
			return (NULL);
		if (lsta->value - lstb->value == 1)
		{
			ptr = lstb->next;
			lsta = push_stack_a_to_b(lstb, lsta, 1);
			lstb = ptr;
			breakman = 1;
		}
		else if (breakman == 1)
			return (lstb);
		else if (flag == 1)
			lstb = rotationfirstlast(lstb, -1);
		else if (flag == -1)
			lstb = reverse_rotate(lstb, -1);
		else if (flag == 0)
			return (reverse_rotate(lstb, -1));
	}
}

t_list	*ft_judgenum(t_list *lsta, t_list *lstb, int value)
{
	int		i;
	int		j;
	t_list	*ptr;

	j = 0;
	i = 0;
	ptr = lstb;
	while (lstb->value != value - 1 && lstb->next != NULL)
	{
		i++;
		lstb = lstb->next;
	}
	lstb = first_to_Lastptr(lstb);
	while (lstb->value != value - 1 && lstb->prev != NULL)
	{
		j++;
		lstb = lstb->prev;
	}
	lstb = ptr;
	if (i < j)
		return (ft_push1(lsta, lstb, 1)); //rb is better
	else if (i > j)
		return (ft_push1(lsta, lstb, -1)); //rrb is better
	else
		return (ft_push1(lsta, lstb, 0));
}

t_list *ft_send_stackl(t_list *lsta, t_list *lstb, int argc)
{
	t_list *ptr;
	int i;

	i = 0;
	while (lsta != NULL)
	{
		if (lsta->value < (argc)-1)
		{
			ptr = lsta->next;
			lstb = push_stack_a_to_b(lsta, lstb, -1);
			lsta = ptr;
			i++;
			if (i == (argc)-1 || ptr == NULL)
				break ;
		}
		else
		{
			if (lsta->next == NULL)
				break ;
			lsta = rotationfirstlast(lsta, 1);
		}
	}
	return lstb;
}

t_list *ft_send_stack(t_list *lsta, t_list *lstb, int argc, int j)
{
	t_list *ptr;
	int i;

	i = 0;
	while( j < 8)
	{
		while (lsta != NULL)
		{
			if (lsta->next == NULL)
				break ;
			if (lsta->value <= (j * argc) / 8)
			{
				ptr = lsta->next;
				lstb = push_stack_a_to_b(lsta, lstb, -1);
				lsta = ptr;
				i++;
				if (i == (j * argc) / 8 || ptr == NULL)
					break ;
			}
			else
				lsta = rotationfirstlast(lsta, 1);
		}
		j++;
	}
	return ft_send_stackl(lsta,lstb,argc);
}


t_list	*ft_algorithm(t_list *lsta, t_list *lstb, int argc)
{
	t_list	*ptr;

	while(lsta->next != NULL && lsta->value != argc - 1)
	{
		lsta = lsta->next;
		ptr = lsta;
	}
	lsta = back_to_Firstptr(ptr);
	lstb = ft_send_stack(lsta,lstb,argc,1);
	lsta = back_to_Firstptr(ptr);
	while (1)
	{
			lstb = ft_judgenum(lsta,lstb,lsta->value);
			lsta = back_to_Firstptr(lsta);
		if (lstb == NULL || ptr->value - lsta->value == argc -1)
			break ;
	}
	return (lsta);
}




