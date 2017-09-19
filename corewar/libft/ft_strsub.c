/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 08:27:11 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/08 08:39:30 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	size_t	i;
	char	*word;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen((char *)s))
		return (NULL);
	word = (char *)malloc(((int)n + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < n)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}
