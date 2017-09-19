/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 13:38:20 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/08/28 09:24:04 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*add_zeroes(char *bins, int i)
{
	while (i < 8)
	{
		bins[i] = '0';
		bins[i + 1] = '0';
		i += 2;
	}
	bins[i] = '\0';
	return (bins);
}

char		*binadd(char *bins, char **string)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (string[++i] && n <= 8)
	{			
		if (string[i][0] == 'r')
		{
			bins[n] = '0';
			bins[n + 1] = '1';
		}
		else if (string[i][0] == '%')
		{
			bins[n] = '1';
			bins[n + 1] = '0';
		}
		else
		{
			bins[n] = '1';
			bins[n + 1] = '1';
		}
		n += 2;
	}
	return (bins);
}
 
long int	hexconv(char *bins)
{
	long int	binval;
	long int	hexval;
	long int	rem;
	int			i;

	i = 1;
	hexval = 0;
	binval = ft_atoi(bins);
	while (binval != 0)
	{
		rem = binval % 10;
		hexval = hexval + rem * i;
		i = i * 2;
		binval = binval / 10;
	}
	return (hexval);
}

int			ft_getacb(char *str)
{
	char		**string;
	char		*bins;
	int			i;
	long int	hexval;

	i = 0;
	str = str + ft_strlen(op_tab[ft_getindex(str)].name);
	while (*str == ' ' || *str == '\t')
		str++;
	bins = (char *)malloc(sizeof(char) * (8));
	string = ft_strsplit(str, ',');
	while (string[i])
	{
		string[i] = ft_trim(string[i]);
		i++;
	}
	bins = binadd(bins, string);
	bins = add_zeroes(bins, i * 2);
	hexval = hexconv(bins);
	return (hexval);
}