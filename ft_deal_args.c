/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:25:47 by shucream          #+#    #+#             */
/*   Updated: 2023/10/08 18:05:27 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_two(t_list *lst)
{
	if (lst->value > lst->next->value)
		lst = swapfirst(lst, 1);
	return (lst);
}

t_list	*ft_deal_argc(t_list *lst, int argc)
{
	lst = back_to_firstptr(lst);
	ft_is_sorted(lst, NULL);
	if (argc == 3)
		lst = ft_sort_two(lst);
	else if (argc == 4)
		lst = ft_sort_three(lst, 1);
	else if (argc == 5)
		lst = ft_sort_four(lst, NULL);
	else if (argc == 6)
		lst = ft_sort_five(lst, NULL);
	else if (argc == 7)
		lst = ft_sort_six(lst, NULL);
	else if (argc == 8)
		lst = ft_algorithm_seven(lst, NULL, argc);
	else
		lst = ft_algorithm(lst, NULL, argc);
	return (lst);
}

t_list	*ft_deal_args(int argc, char **argv)
{
	int		*return_sort;
	int		*sort;
	int		i;
	t_list	*x;

	sort = (int *)malloc(argc * sizeof(int));
	if (sort == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		sort[i - 1] = ft_advanced_atoi(argv[i], sort);
		i++;
	}
	ft_isdouble_error(sort, argc);
	return_sort = rank(sort, argc - 1, 0, 0);
	free(sort);
	i = 0;
	while (i < argc - 1)
	{
		x = addlst(return_sort[i], x);
		i++;
	}
	free(return_sort);
	return (ft_deal_argc(x, argc));
}
