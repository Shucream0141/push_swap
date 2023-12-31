/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sendo <sendo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:25:40 by sendo             #+#    #+#             */
/*   Updated: 2023/06/05 15:52:07 by sendo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*d;

	d = (char *)s;
	while (n--)
	{
		*d = '\0';
		d++;
	}
}

// int	main(void)
// {
// 	char buf[] = "1234567890";

// 	bzero(buf, 3);
// 	printf("%s\n", buf);
// 	ft_bzero(buf, 3);
// 	printf("%s\n", buf);
// 	return (0);
// }