/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shucream <shucream@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:46:21 by shucream          #+#    #+#             */
/*   Updated: 2023/09/24 02:08:12 by shucream         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
errorのチェックでは、
１、sortされてたらそのまま->これは前後のリストを引いたら差が１になって最後まで行けばよし、そうでないならソート
２、重複を探すには、、、atoiでもらったやつをどっかにぶち込んでそこで処理しないときつそう、二重で回して同じやつがあったらフラグ立てて消せばいい
３、変な文字が入ってたらerrorにする、これはatoiを作らないとわからない
*/

int ft_is_sorted(t_list *lsta,t_list *lstb)
{
    while(lsta->next != NULL && lsta->value - lsta->next->value != 1)
        lsta = lsta->next;
    if(lsta->next == NULL)
    {
        printf("error\n");
        ft_freeall(lsta,lstb);
        exit(1);
    }
    return 0;
}

int ft_double_error(int *sort,int argc)
{
    int i;
    int j;

    i = 0;
    while(i < argc - 1)
    {
        j = 1;
        while(i + j < argc - 1)
        {
            if(sort[i] == sort[i + j])
            {
                printf("error\n");
                free(sort);
                exit(1);
            }
            j++;
        }
        i++;
    }
    return 0;
}

int ft_advanced_atoi()
{
    
}

int main(int argc, char **argv)
{
    t_list *x;
    int i;
    int *sort;
    int *return_sort;

    x = NULL;
    i = 1;
	sort = (int *)malloc(argc * sizeof(int));
	while (i < argc)
	{
		sort[i - 1] = atoi(argv[i]);
		i++;
	}
    if(ft_double_error(sort,argc) == 0)
        printf("ok");
	return_sort = rank(sort, argc - 1, 0, 0);
    i = 0;
	while (i < argc - 1)
	{
		x = addlst(return_sort[i], x);
		i++;
	}
    x = back_to_Firstptr(x);
    if(ft_is_sorted(x,NULL) == 0)
        printf("ok");
    return 0;
}