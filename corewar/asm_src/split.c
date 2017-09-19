/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 07:23:54 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/14 15:17:56 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	remain(char *s, int i)
{
	int j;

	j = 0;
	while (s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_fill(char *s, int k)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * ft_strlen(s));
	i = 8 - k;
	while (i >= 0)
	{
		new[i] = '0';
		i--;
	}
	return (new);
}

int	split_byte(char *s, int i)
{
	char	*new;
	int		j;
	int		k;
	int		num;

	j = 0;
	new = (char *)malloc(sizeof(char) * 8);
	if ((k = remain(s, i)) < 8)
	{
		j = 8 - k;
		new = ft_fill(new, k);
	}
	while (s[i] && j < 8)
	{
		new[j] = s[i];
		j++;
		i++;
	}
	new[j] = '\0';
	num = ft_atoi_base(new, 16);
	free(new);
	return (num);
}
