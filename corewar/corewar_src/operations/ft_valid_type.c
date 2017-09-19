/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:28:24 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/09/18 12:10:32 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include "../../includes/vm.h"

int		valid_reg(int num)
{
	return ((num < REG_NUMBER && num > 0) ? 1 : 0);
}

int		is_direct(int enc_oct, int num_param)
{
	int		i;

	i = 1;
	while (i < num_param)
	{
		enc_oct = enc_oct << 2;
		i++;
	}
	if ((enc_oct & 0b11000000) == 0b10000000)
		return (1);
	return (0);
}

int		is_indirect(int enc_oct, int num_param)
{
	int		i;

	i = 1;
	while (i < num_param)
	{
		enc_oct = enc_oct << 2;
		i++;
	}
	if ((enc_oct & 0b11000000) == 0b11000000)
		return (1);
	return (0);
}

int		is_reg(int enc_oct, int num_param)
{
	int		i;

	i = 1;
	while (i < num_param)
	{
		enc_oct = enc_oct << 2;
		i++;
	}
	if ((enc_oct & 0b11000000) == 0b01000000)
		return (1);
	return (0);
}
