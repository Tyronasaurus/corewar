/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 07:23:52 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/01 08:55:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!((int *)dest > (int *)src && (int *)src + n > (int *)dest))
		ft_memcpy(dest, (void *)src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *)dest + i) = *((char *)src + i);
		}
	}
	return (dest);
}
