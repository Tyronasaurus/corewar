/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 08:13:20 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/12 13:08:40 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char	*convert_name(char *str)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	s = str;
	s = atoh(s);
	return (s);
}

t_point	convert_comment(t_point point)
{
	int		i;

	i = 0;
	point.h_comment = (char *)malloc(sizeof(char)
				* (ft_strlen(point.comment) + 1));
	point.h_comment = point.comment;
	point.h_comment = atoh(point.h_comment);
	while (point.h_comment[i + 8])
	{
		i += 8;
		point.size += 2;
	}
	return (point);
}
