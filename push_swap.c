/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:51 by sendo             #+#    #+#             */
/*   Updated: 2023/09/12 12:33:51 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackprint(t_list *stack)
{
	printf("%d\n", stack->content);
}

t_list	*stackman(t_list *prev, int num)
{
	prev->next = ft_lstnew(num);
	return (prev->next);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		num;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		new->next = new;
		i++;
	}
	return (0);
}

//ここから拡張していく。まず必要なのは大小の数値比較だからatoiにぶち込んで(ok)スタックに積みたい。
//構造体にちゃんと数字が積めているか格納できてるか確かめる関数を作る。
//