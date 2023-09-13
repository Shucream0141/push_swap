/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:33:55 by sendo             #+#    #+#             */
/*   Updated: 2023/09/12 18:34:18 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rank(int *lst, int arg_num, int max, int num)
{
	int			*sorted;
	int			i;
	int	j;

	j = 0;
	sorted = (int *)malloc(arg_num * sizeof(int));
	if (sorted == NULL)
		return (NULL);
	while (j < arg_num)
	{
		i = 0;
		max = 0;
		while (i < arg_num)
		{
			if (max < lst[i])
			{
				max = lst[i];
				num = i;
			}
			i++;
		}
		lst[num] = -1;
		sorted[num] = arg_num - j;
		j++;
	}
	return (sorted);
}


t_list *back_to_Firstptr(t_list *lst)
{
	if(lst == NULL)
		return NULL;
    while(lst->prev != NULL)
    {
        lst = lst->prev;
		// printf("utils%p\n",lst);
    }
    return lst;
}

void	printstack(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->value);
		if(lst->next != NULL)
			lst = lst->next;
		else
			break;
	}
}

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