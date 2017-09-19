/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:18:26 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/13 12:56:19 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		label_chars(char s)
{
	int	i;
	int	value;

	value = 0;
	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (LABEL_CHARS[i] == s)
			value++;
	}
	if (value > 0)
		return (0);
	return (-1);
}

int		check_label(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ':' && s[i] == '\0')
		i++;
	if (s[i - 1] == '%' || i != (int)ft_strlen(s))
		return (0);
	else
	{
		while (i >= 0)
		{
			if (label_chars(s[i]) == -1)
				return (-1);
			i--;
		}
	}
	return (1);
}
