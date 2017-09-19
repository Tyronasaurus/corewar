/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:43:11 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/13 13:05:42 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_point	get_lines(t_point point, char *line)
{
	int	y;
	int	i;

	y = 0;
	point.lbl_err = 0;
	point.label = (char **)malloc(sizeof(char *));
	while (get_next_line(point.fd, &line) != 0)
	{
		i = -1;
		if ((check_label(line)) == -1 || line[0] == '.')
		{
			print_error(3);
			point.lbl_err = -1;
		}
		point.label[y] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		while (line[++i])
			point.label[y][i] = line[i];
		point.label[y][i] = '\0';
		y++;
	}
	point.lbl_size = y;
	point.label[y] = "";
	return (point);
}

t_point	get_comment(t_point point, char *line)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (line[i] != '"')
		i++;
	while (line[++i] != '"' && i < 2048)
	{
		point.comment[l] = line[i];
		l++;
	}
	return (point);
}

t_point	get_name(t_point point, char *line)
{
	int		i;
	int		l;

	i = 0;
	while (line[i] != '"')
		i++;
	l = 0;
	while (line[++i] != '"')
	{
		point.name[l] = line[i];
		l++;
	}
	point.name[i] = '\0';
	return (point);
}

int		file_open(t_point point)
{
	if (point.fd < 0)
	{
		print_error(2);
		return (-1);
	}
	return (0);
}

int		text(char *file_name)
{
	char	*line;
	t_point	point;

	point.file = (char *)malloc(sizeof(char) * ft_strlen(file_name));
	point.file = ft_strdup(file_name);
	point.fd = open(file_name, O_RDWR);
	if (file_open(point) == -1)
		return (-1);
	get_next_line(point.fd, &line);
	if (ft_strncmp(line, ".name \"", 6) == 0)
		point = get_name(point, line);
	else
		return (-1);
	get_next_line(point.fd, &line);
	if (ft_strncmp(line, ".comment \"", 10) == 0)
		point = get_comment(point, line);
	else
		return (-1);
	point = create_file(point, file_name);
	point = get_lines(point, line);
	if (point.fd_2 == -1 || (point.lbl_err == -1))
		return (-1);
	print(point);
	return (0);
}
