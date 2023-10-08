/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:46:21 by shucream          #+#    #+#             */
/*   Updated: 2023/10/08 18:48:27 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
errorのチェックでは、
１、sortされてたらそのまま->これは前後のリストを引いたら差が１になって最後まで行けばよし、そうでないならソート
２、重複を探すには、、、atoiでもらったやつをどっかにぶち込んでそこで処理しないときつそう、二重で回して同じやつがあったらフラグ立てて消せばいい
３、変な文字が入ってたらerrorにする、これはatoiを作らないとわからない
*/

int	ft_is_sorted(t_list *lsta, t_list *lstb)
{
	while (lsta->next != NULL && lsta->next->value - lsta->value == 1)
		lsta = lsta->next;
	if (lsta->next == NULL)
	{
		ft_freeall(lsta, lstb);
		exit(0);
	}
	return (0);
}

int	ft_isdouble_error(int *sort, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 1;
		while (i + j < argc - 1)
		{
			if (sort[i] == sort[i + j])
			{
				write(2, "Error\n", 6);
				free(sort);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	over(long num, int count)
{
	if (count == 0 && (num > INT_MAX || num < INT_MIN))
		return (1);
	else if (count == 1 && ((-1 * num) > INT_MAX || (-1 * num) < INT_MIN))
		return (1);
	return (0);
}

int	ft_check_str_l(const char *str, int *sort, int count)
{
	long	num;

	num = 0;
	if (*str == '\0' || count > 1)
		ft_exit_print(sort);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		if (over(num, count) == 1)
			ft_exit_print(sort);
		str++;
	}
	if (*str != '\0')
		ft_exit_print(sort);
	return (num);
}

int	ft_advanced_atoi(const char *str, int *sort)
{
	int		count;
	long	num;

	num = 0;
	count = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			count++;
		str++;
	}
	num = ft_check_str_l(str, sort, count);
	if (count == 1)
		num *= -1;
	return (num);
}

// int main(int argc, char **argv)
// {
//     t_list *x;
//     int i;
//     int *sort;
//     int *return_sort;

//     i = 1;
// 	sort = (int *)malloc(argc * sizeof(int));
// 	while (i < argc)
// 	{
// 		sort[i - 1] = ft_advanced_atoi(argv[i],sort);
//         printf("%d\n",sort[i - 1]);
// 		i++;
// 	}
//     if(ft_isdouble_error(sort,argc) == 0)
//         printf("ok");
// 	return_sort = rank(sort, argc - 1, 0, 0);
//     i = 0;
// 	while (i < argc - 1)
// 	{
// 		x = addlst(return_sort[i], x);
// 		i++;
// 	}
//     x = back_to_Firstptr(x);
//     if(ft_is_sorted(x,NULL) == 0)
//         printf("ok");
//     return (0);
// }

//  cc ft_check_err.c ft_stack.c ft_utils.c