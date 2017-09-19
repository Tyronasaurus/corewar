/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 08:48:16 by cpauwels          #+#    #+#             */
/*   Updated: 2017/08/31 07:04:05 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*fstr;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	fstr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (fstr == NULL)
		return (NULL);
	while (s1[++i])
		fstr[i] = s1[i];
	while (s2[++j])
	{
		fstr[i] = s2[j];
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
