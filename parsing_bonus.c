/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:05:36 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/24 15:05:38 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkligne(t_data *data)
{
	int	k;
	int	l;
	int	d;

	k = 0;
	while (k < (data->map_h - 1))
	{
		d = ft_strlen(data->map[k]);
		l = ft_strlen(data->map[k + 1]);
		if (d != l)
			return (0);
		k++;
	}
	return (1);
}

int	checkwall(t_data *data)
{
	int	k;
	int	q;
	int	e;

	k = 0;
	q = ft_strlen(data->map[0]);
	e = ft_strlen(data->map[data->map_h - 1]);
	while (k < data->map_w)
	{
		if (q != e || data->map[0][k] != data->map[data->map_h - 1][k])
			return (0);
		k++;
	}
	k = 0;
	while (k < data->map_h)
	{
		if (data->map[k][0] != data->map[k][data->map_w - 1])
			return (0);
		k++;
	}
	return (1);
}

int	checkchar(t_data *data)
{
	int	k;
	int	f;

	k = 0;
	while (k < data->map_h)
	{
		f = 0;
		while (f < data->map_w)
		{
			if (data->map[k][f] != '1' && data->map[k][f] != 'C' &&
					data->map[k][f] != 'P' && data->map[k][f] != 'E' &&
					data->map[k][f] != '0' && data->map[k][f] != 'N')
				return (0);
			f++;
		}
		k++;
	}
	return (1);
}

int	check_validchar(t_data *data)
{
	int	k;
	int	l;
	int	c;
	int	r;

	k = 0;
	c = 0;
	r = 0;
	while (k < data->map_h)
	{
		l = 0;
		while (l < data->map_w)
		{
			if (data->map[k][l] == 'P' || data->map[k][l] == 'E')
				c++;
			if (data->map[k][l] == 'C')
				r++;
			l++;
		}
		k++;
	}
	if (c != 2 || r == 0)
		return (0);
	return (1);
}

void	norm(int arg, t_data *data)
{
	if (!data)
		exit(write(1, "Error\nerror in allocation", 25));
	if (arg != 2)
		exit(write(1, "Error\nerror argument!", 21));
}
