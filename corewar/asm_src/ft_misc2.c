/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:43:33 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/07 14:43:34 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_arg_type	ft_gettype(char *param)
{
	while (*param == ' ' || *param == '\t')
		param++;
	if (*param == 'r')
		return (T_REG);
	else if (*param == '%')
		return (T_DIR);
	return (T_IND);
}

char		*ft_gethex(int num, int len)
{
	char		*s;
	const char	hex[] = "0123456789abcdef";

	s = ft_strnew(len);
	if (len & 1)
		*s++ = '0';
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = hex[num & 0xf];
		num >>= 4;
		len--;
	}
	return (s);
}
