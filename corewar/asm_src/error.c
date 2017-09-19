/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 07:56:02 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/04 10:58:29 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_error(int num)
{
	if (num == 1)
		write(2, "Error: Insufficient arguments\n", 30);
	if (num == 2)
		write(2, "Error: File does not exist or already exists\n", 57);
	if (num == 3)
		write(2, "Error: Invalid File\n", 20);
}
