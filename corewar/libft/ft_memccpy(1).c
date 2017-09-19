/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 07:37:44 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/10 07:04:48 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)src;
	s2 = (char*)dst;
	while (n > 0 && *s1 != c)
	{
		*s2++ = *s1++;
		n = n - 1;
	}
	if (n > 0)
	{
		*s2++ = *s1++;
		return ((void *)s2);
	}
	return (NULL);
}
