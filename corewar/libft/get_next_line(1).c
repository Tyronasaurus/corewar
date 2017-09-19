/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:53:40 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/25 08:11:58 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*append_char(char *s, char c)
{
	char	*str;
	int		i;

	if (c == '\n')
		return (s);
	str = ft_strnew(ft_strlen(s) + 1);
	if (str)
	{
		i = 0;
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = c;
		i++;
		str[i] = '\0';
		ft_strdel(&s);
		return (str);
	}
	return (NULL);
}

static	int		check_return(int i, char *line_num)
{
	if (i < 0)
		return (-1);
	else if (i > 0)
	{
		return (1);
	}
	else if (i == 0 && *line_num)
	{
		return (1);
	}
	else if (line_num != NULL)
		ft_strdel(&line_num);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_line t;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == NULL)
		return (-1);
	while (t.buf[t.i])
	{
		*line = append_char(*line, t.buf[t.i]);
		if (t.buf[t.i++] == '\n')
			return (1);
	}
	while ((t.ret = read(fd, t.buf, BUFF_SIZE)) > 0)
	{
		t.buf[t.ret] = '\0';
		t.i = 0;
		while (t.buf[t.i])
		{
			*line = append_char(*line, t.buf[t.i]);
			if (t.buf[t.i++] == '\n')
				return (1);
		}
	}
	return (check_return(t.ret, *line));
}
