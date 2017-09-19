/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/08/25 16:04:49 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*ft_get_reg(char *cmd)
{
	char	*out;

	while (*cmd == ' ' || *cmd == 'r')
		cmd++;
	out = ft_gethex(ft_atoi(cmd), 2);
	return (out);
}

char		*ft_get_dir(t_cmd *c, char *cmd, int is_index)
{
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	if (cmd[0] == '%' && cmd[1] != ':')
	{
		if (!is_index)
			return (ft_gethex(ft_atoi(&cmd[1]), 8));
		else
			return (ft_gethex(ft_atoi(&cmd[1]), 4));
	}
	else if (cmd[0] == '%' && cmd[1] == ':')
		return (ft_get_lbl(c, &cmd[2]));
	return (NULL);
}

char		*ft_get_ind(char *cmd)
{
	return (ft_gethex(ft_atoi(cmd), 2));
}