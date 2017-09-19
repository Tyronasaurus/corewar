/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:05:25 by cpauwels          #+#    #+#             */
/*   Updated: 2017/05/29 16:35:31 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *word)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	c = 0;
	if (word[0] == '\0')
		return (char*)(str);
	while (str[i] != '\0')
	{
		j = i;
		c = 0;
		while (str[j] == word[c])
		{
			j++;
			c++;
			if (word[c] == '\0')
				return (char*)(&str[i]);
		}
		i++;
	}
	return (NULL);
}
