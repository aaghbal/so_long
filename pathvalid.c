/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathvalid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:39:56 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/17 23:40:00 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(int *p1, int x, int y, t_data *data)
{
	if (data->map2[x][y] == 'C')
		(*p1)++;
}

int	checkpath_col(int x, int y, t_data *data)
{
	static int	j = 0;
	static int	col = 0;

	if (j == 0)
	{
		conv_e(data);
		cole_len(data);
		j = 1;
	}
	data->map2[x][y] = '1';
	if (data->map2[x][y + 1] != '1')
		helper(x, y + 1, &col, data);
	if (data->map2[x][y - 1] != '1')
		helper(x, y - 1, &col, data);
	if (data->map2[x + 1][y] != '1')
		helper(x + 1, y, &col, data);
	if (data->map2[x - 1][y] != '1')
		helper(x - 1, y, &col, data);
	if (col == data->num_col)
		return (1);
	return (0);
}

void	helper(int x, int y, int *col, t_data *data)
{
	check(col, x, y, data);
	checkpath_col(x, y, data);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
