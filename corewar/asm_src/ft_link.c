/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/13 13:12:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_addlabel(t_cmd **c, char *str)
{
	char	*lbl;
	char	*cmd;
	int		i;

	i = ft_find(str, ':');
	lbl = ft_strsub(str, 0, i);
	cmd = ft_strdup(&str[i + 1]);
	i = -1;
	while (lbl[++i])
		if (ft_find(LABEL_CHARS, lbl[i]) < 0)
			printf("Error: Invalid characters in label.\n");
	if (ft_strlen(cmd) <= 0 || ft_isempty(cmd))
		ft_push_cmd(c, NULL, lbl);
	else if (ft_strlen(cmd) > 0 && !ft_isempty(cmd))
		if (ft_valid(c, cmd, lbl) == TRUE)
		{
			printf("Error2: Invalid command\n");
			return ;
		}
	free(lbl);
	free(cmd);
}

char		*ft_link(char **str, int len)
{
	int		i;
	int		error;
	t_cmd	*c;
	char	*out;

	i = -1;
	while (++i < len)
		printf("str : '%s'\n", str[i]);

	i = 1;
	c = NULL;
	error = FALSE;
	while (i < len && error == FALSE)
	{
		if (ft_find(str[i], ':') > -1 && str[i][ft_find(str[i], ':') - 1] != '%')
			ft_addlabel(&c, str[i]);
		else if (ft_trim(str[i])[0] != '#' && !ft_isempty(str[i]))
		{
			error = ft_valid(&c, str[i], NULL);
		}
		i++;
	}
	if (error == TRUE)
	{
		printf("Erorr1: Invalid command\n");
		return (NULL);
	}
	out = ft_hex(&c);
	printf("---------- HEX ----------\n%s\n", out);
	return (out);
}
