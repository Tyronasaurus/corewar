/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/08/25 16:04:49 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_count(int i, char **params)
{
	int		k;
	int		out;

	k = -1;
	out = 0;
	while (params[++k])
	{
		if (ft_gettype(params[k]) == T_REG)
			out++;
		else if (ft_gettype(params[k]) == T_DIR && params[k][1] != ':')
			if (op_tab[i].is_index != 1)
				out += 4;
			else
				out += 2;
		else if (ft_gettype(params[k]) == T_DIR && params[k][1] == ':')
			out += 2;
		else
			out += 2;
	}
	return (out);
}

static int	ft_count_line(char *cmd)
{
	int		i;
	int		out;
	char	**params;

	out = 0;
	if ((i = ft_getindex(cmd)) != -1)
		out++;
	if (op_tab[i].has_acb)
		out++;
	cmd = cmd + ft_strlen(op_tab[i].name);
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	params = ft_strsplit(cmd, ',');
	out += ft_count(i, params);
	free(params);
	return (out);
}

static int	ft_look_down(t_cmd *c, char *lbl)
{
	int		out;

	out = 0;
	while (c)
	{
		if (c->label)
			if (ft_strncmp(c->label, lbl, ft_strlen(c->label)) == 0)
				return (out);
		if (c->cmd)
			out += ft_count_line(c->cmd);
		c = c->next;
	}
	return (0);
}

static int	ft_look_up(t_cmd *c, char *lbl)
{
	int		out;

	out = 0;
	while (c)
	{
		if (c->cmd)
			out -= ft_count_line(c->cmd);
		if (c->label)
			if (ft_strncmp(c->label, lbl, ft_strlen(c->label)) == 0)
				return (out);
		c = c->prev;
	}
	return (0);
}

char		*ft_get_lbl(t_cmd *c, char *lbl)
{
	int		out;

	out = 0;
	out = ft_look_down(c, lbl);
	if (out == 0)
		out = ft_look_up(c->prev, lbl);
	return (ft_gethex(out, 4));
}
