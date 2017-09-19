/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:40:40 by cpauwels          #+#    #+#             */
/*   Updated: 2017/05/29 14:28:46 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	dup = (char *)malloc(ft_strlen(s) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dup, s);
	return (dup);
}
