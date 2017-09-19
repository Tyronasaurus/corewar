/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 07:23:24 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/13 09:48:37 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_point	create_file(t_point point, char *s)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s) - 2));
	while (i < (int)(ft_strlen(s) - 2))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	new = ft_strjoin(new, ".cor");
	point.file = (char *)malloc(sizeof(char) * ft_strlen(new));
	point.file = new;
	point.fd_2 = open(new, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (point.fd_2 == -1)
		print_error(2);
	return (point);
}
