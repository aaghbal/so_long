/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:34:55 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/23 22:34:57 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cal_move(t_data *data, int *p)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.wall, 32, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img.wall, 64, 0);
	mlx_string_put(data->mlx, data->win, 0, 0, 0XFFFF00, "move");
	mlx_string_put(data->mlx, data->win, 13, 13, 0XFFFF00,
		ft_itoa(*p));
}

void	ft_count2(t_data *data)
{
	static int	i = 0;

	if (i == 0)
	{
		cole_len2(data);
		i = 1;
	}
}

void	cole_len2(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map[i][j] == 'C')
				data->num_col2++;
			j++;
		}
		i++;
	}
}

void	initial_var(t_data *data)
{
	data->dir = 0;
	data->f = 0;
	data->frams = 0;
	data->imgag_frams = 0;
	posenemy(data);
	put_image(data);
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, ft_esc, data);
	mlx_loop_hook(data->mlx, move_ene, data);
}
