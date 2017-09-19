/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:13:20 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/14 15:15:25 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_int(t_point point, char *num)
{
	int		l;
	int		i;
	int		k;
	int		p;
	int		skip;

	i = 0;
	l = ft_atoi_base(num, 16);
	skip = 0;
	while (num[i] && skip == 0)
	{
		skip = 0;
		l = split_byte(num, i);
		if ((k = remain(num, i)) < 8)
			skip = 1;
		if (k <= 2)
			skip = 2;
		ft_reverse_bytes(&l, sizeof(l), skip);
		if (skip != 0)
			p = (8 - k) / 2;
		write(point.fd_2, &l, sizeof(l) - p);
		i += 8;
	}
}

void	print_filler(t_point point, int lim)
{
	char	*s;
	int		i;
	int		num;

	i = 0;
	s = (char *)malloc(sizeof(char) * 2);
	s = "0x";
	num = ft_atoi_base(s, 16);
	while (i <= lim)
	{
		write(point.fd_2, &num, sizeof(num));
		i++;
	}
}

void	print_to_file(t_point point, char *s)
{
	int	i;
	int	num;
	int	skip;
	int	p;
	int k;

	i = 0;
	while (s[i])
	{
		skip = 0;
		p = 0;
		num = split_byte(s, i);
		if ((k = remain(s, i)) < 8)
			skip = 1;
		if (k <= 2)
			skip = 2;
		ft_reverse_bytes(&num, sizeof(num), skip);
		if (skip == 2)
			p = (8 - k) / 2;
		else if (k == 4)
			p = (8 - k) / 2 - 1;
		write(point.fd_2, &num, sizeof(num) - p);
		i += 8;
	}
}

void	print_exec_magic(t_point point)
{
	int	b;

	b = COREWAR_EXEC_MAGIC;
	ft_reverse_bytes(&b, sizeof(b), 0);
	write(point.fd_2, &b, sizeof(b));
}

void	print(t_point point)
{
	int		i;
	int		num;
	char	*lbl;

	i = -1;
	point.size = 0;
	print_exec_magic(point);
	point.h_name = convert_name(point.name);
	print_to_file(point, point.h_name);
	num = (128 - ft_strlen(point.name)) / 4;
	print_filler(point, num);
	point.size = 0;
	point = convert_comment(point);
	lbl = ft_link(point.label, point.lbl_size);
	point.size += ft_strlen(lbl) / 4;
	ft_reverse_bytes(&point.size, sizeof(point.size), 0);
	write(point.fd_2, &point.size, sizeof(point.size));
	printf("comment\n");
	print_to_file(point, point.h_comment);
	num = (2048 - ft_strlen(point.comment)) / 4;
	print_filler(point, num);
	print_int(point, lbl);
}
