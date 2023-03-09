/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathvalid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:32:41 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/20 19:32:43 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check1(int *p2, int x, int y, t_data *data)
{
	if (data->map2[x][y] == 'E')
		(*p2)--;
}

int	checkpath_ex(int x, int y, t_data *data)
{
	static int	ex = 1;

	conv_c (data);
	data->map3[x][y] = '1';
	if (data->map3[x][y + 1] != '1')
		helper2(x, y + 1, &ex, data);
	if (data->map3[x][y - 1] != '1')
		helper2(x, y - 1, &ex, data);
	if (data->map3[x + 1][y] != '1')
		helper2(x + 1, y, &ex, data);
	if (data->map3[x - 1][y] != '1')
		helper2(x - 1, y, &ex, data);
	if (ex == 0)
		return (1);
	return (0);
}

void	helper2(int x, int y, int *col, t_data *data)
{
	check1(col, x, y, data);
	checkpath_ex(x, y, data);
}

void	ft_count(t_data *data)
{
	static int	i = 0;

	if (i == 0)
	{
		cole_len(data);
		i = 1;
	}
}
