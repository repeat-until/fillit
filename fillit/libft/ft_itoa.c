/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:41:46 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/08 23:18:40 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	size;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	s[size] = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
		n *= -1;
	}
	while (i < size--)
	{
		s[size] = ((n % 10) + 48);
		n /= 10;
	}
	return (s);
}
