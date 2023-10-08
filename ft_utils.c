/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:55 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 12:23:17 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rank(int *lst, int arg_num, int max, int num)
{
	int	*sorted;
	int	i;
	int	j;

	j = 0;
	sorted = (int *)malloc(arg_num * sizeof(int));
	free_exit(sorted, lst);
	while (j < arg_num)
	{
		i = 0;
		max = INT_MIN;
		while (i < arg_num)
		{
			if (max < lst[i])
			{
				max = lst[i];
				num = i;
			}
			i++;
		}
		lst[num] = INT_MIN;
		sorted[num] = arg_num - j;
		j++;
	}
	return (sorted);
}

void	*ft_freeall(t_list *lsta, t_list *lstb)
{
	t_list	*ptr;

	lsta = back_to_firstptr(lsta);
	lstb = back_to_firstptr(lstb);
	while (lsta != NULL)
	{
		ptr = lsta->next;
		free(lsta);
		lsta = ptr;
	}
	while (lstb != NULL)
	{
		ptr = lstb->next;
		free(lstb);
		lstb = ptr;
	}
	return (NULL);
}

t_list	*back_to_firstptr(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}

t_list	*first_to_lastptr(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// t_list	*rra(t_list *lsta, t_list *lstb)
// {
// 	lsta = reverse_rotate(lsta, 1);
// 	lstb = reverse_rotate(lstb, -1);
// 	ft_printf("rrr\n");
// 	return (lsta);
// }

// void	printstack(t_list *lst)
// {
// 	while (lst != NULL)
// 	{
// 		printf("%d\n", lst->value);
// 		if (lst->next != NULL)
// 			lst = lst->next;
// 		else
// 			break ;
// 	}
// }

// #include<stdlib.h>
// int main(int argc,char **argv)
// {
// 	int i = 0;
// 	int *sort = (int *)malloc(argc * sizeof(int));
// 	int *return_sort =(int *)malloc(argc * sizeof(int));
// 	printf("%d\n\n",argc);
// 	while(i < argc - 1)
// 	{
// 		sort[i] = atoi(argv[i + 1]);
// 		printf("sortです%d\n",sort[i]);
// 		i++;
// 	}
// 		return_sort = rank(sort,argc - 1,0,0);
// 	i = 0;
// 	while(i < argc -1)
// 	{
// 		printf("sortです%d\n",return_sort[i]);
// 		i++;
// 	}
// }