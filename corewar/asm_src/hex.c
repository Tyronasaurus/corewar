/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:36:57 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/04 11:30:32 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*convert(char a)
{
	char	c;
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	c = (a >> 4) & 0x0f;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	s[0] = c;
	c = a & 0x0f;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	s[1] = c;
	return (s);
}

char	*atoh(char *str)
{
	char	*s;
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(sizeof(char) * 2);
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) * 3));
	while (str[i])
	{
		c = convert(str[i]);
		s = ft_strjoin(s, c);
		i++;
	}
	return (s);
}
