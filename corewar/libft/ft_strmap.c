/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 07:38:41 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/08 07:46:11 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*fstr;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s);
	fstr = (char *)malloc((j + 1) * sizeof(char));
	if (fstr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		fstr[i] = f(s[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
