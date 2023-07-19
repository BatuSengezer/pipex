/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:40:22 by bsengeze          #+#    #+#             */
/*   Updated: 2022/12/20 19:12:34 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != 0)
	{
		j = 0;
		while (little[j] == big[i + j] && len > i + j)
		{
			if (little[j + 1] == 0)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
	printf("my func result %s\n", ft_strnstr("lorem ipsum dolor","ipsumm",6));
    //printf("lib func result %s", strnstr("lorem ipsum","ipsumm",6));
}
*/
