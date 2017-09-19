/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:02:30 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/09/04 11:01:21 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_blank(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r' ||
			c == '\f');
}

int			ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= ('a' + base - 10)));
}

long int	ft_atoi_base(char *str, int base)
{
	long int	res;
	int			neg;

	res = 0;
	while (is_blank(*str))
		str++;
	neg = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'a' >= 0)
			res = res * base + (*str - 'a' + 10);
		else
			res = res * base + (*str - '0');
		str++;
	}
	return (res * neg);
}
