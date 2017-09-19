/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarlow- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:00:02 by tbarlow-          #+#    #+#             */
/*   Updated: 2017/09/18 12:30:22 by tbarlow-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		ft_add(t_op *op, t_champ *champ)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (valid_reg(op.param_types[0]) == 1)
		a = champ->pc->value[0];
	if (valid_reg(op.param_types[1]) == 1)
		b = champ->pc->value[1];
	if (valid_reg(op.param_types[2]) == 1)
		champ->pc->value[2] = a + b;
	champ->carry = (a + b) ? 0 : 1;
	return (0);
}
