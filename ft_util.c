/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:22:56 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 18:49:53 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(int *sorted, int *lst)
{
	if (sorted == NULL)
	{
		free(lst);
		exit(1);
	}
}

void	double_free(int *sort, int *return_sort)
{
	free(sort);
	free(return_sort);
}

void	ft_exit_print(int *sort)
{
	write(2, "Error\n", 6);
	free(sort);
	exit(1);
}
