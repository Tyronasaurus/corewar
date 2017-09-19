/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:55:14 by rheukelm          #+#    #+#             */
/*   Updated: 2017/08/29 12:55:15 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			ft_getindex(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (i < 16)
	{
		len = ft_strlen(op_tab[i].name);
		if (ft_strncmp(str, op_tab[i].name, len) == 0 &&
		(str[len] == 9 || str[len] == ' '))
			return (i);
		i++;
	}
	return (-1);
}

char		*ft_trim(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;
	return (str);
}

int			ft_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_find(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (i);
	return (-1);
}

int			ft_isempty(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	return (1);
}
