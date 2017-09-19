/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 06:51:47 by cpauwels          #+#    #+#             */
/*   Updated: 2017/05/30 06:51:55 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *word, size_t n)
{
	size_t	len2;

	if (*word == '\0')
		return ((char *)str);
	len2 = ft_strlen(word);
	while (*str != '\0' && n-- >= len2)
	{
		if (*str == *word && ft_memcmp(str, word, len2) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
