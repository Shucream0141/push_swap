/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:34:12 by sendo             #+#    #+#             */
/*   Updated: 2023/10/08 20:04:16 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	ft_freeall(ft_deal_args(argc, argv), NULL);
	return (0);
}

// __attribute__((destructor))
// void    destructor(void)
// {
//     int     status;
//     char    buf[50];

//     snprintf(buf, 50, "leaks %d &> leaksout", getpid());
//     status = system(buf);
//     if (status)
//     {
//         write(2, "leak!!!\n", 8);
//         system("cat leaksout >/dev/stderr");
//         exit(1);
//     }
// }

/*
文字列を受け取るときchar*この中から、
splitを用いてスペースを取り除いたものを入れる


*/