/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:53:22 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/24 13:53:24 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	posenemy(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_h)
	{
		y = 0;
		while (y < data->map_w)
		{
			if (data->map[x][y] == 'N')
			{
				data->en_x = x;
				data->en_y = y;
				return ;
			}
		y++;
		}
	x++;
	}
}

void	move_ene_down(t_data *data)
{
	if (data->map[data->en_x + 1][data->en_y] == 'P')
		exit(write(1, "YOU LOSE", 8));
	else if (data->map[data->en_x + 1][data->en_y] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->en_y * 32, data->en_x * 32);
		data->map[data->en_x][data->en_y] = '0';
		data->en_x++;
		data->map[data->en_x][data->en_y] = 'N';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.enemy, data->en_y * 32, data->en_x * 32);
	}
	else
		data->dir = 0;
}

void	move_ene_up(t_data *data)
{
	if (data->map[data->en_x - 1][data->en_y] == 'P')
		exit(write(1, "YOU LOSE", 8));
	else if (data->map[data->en_x - 1][data->en_y] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->en_y * 32, data->en_x * 32);
		data->map[data->en_x][data->en_y] = '0';
		data->en_x--;
		data->map[data->en_x][data->en_y] = 'N';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.enemy1, data->en_y * 32, data->en_x * 32);
	}
	else
		data->dir = 1;
}

void	put_coin(t_data *data)
{
	data->x = 0;
	while (data->x < data->map_h)
	{
		data->y = 0;
		while (data->y < data->map_w)
		{
			if (data->map[data->x][data->y] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.fr_spac, data->y * 32, data->x * 32);
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.colec, data->y * 32, data->x * 32);
			}
			data->y++;
		}
		data->x++;
	}
}

int	move_ene(t_data *data)
{
	if (data->map[data->en_x - 1][data->en_y] == '1' &&
		data->map[data->en_x + 1][data->en_y] == '1')
		exit(write(1, "Ereur\nerror enemy", 17));
	if (data->frams == 60)
	{
		move_coin(data);
		put_coin(data);
		if (data->dir == 0)
			move_ene_up(data);
		else
			move_ene_down(data);
		data->frams = 0;
	}
	else
	{
		if (data->f == 20)
		{
			data->frams++;
			data->f = 0;
		}
		else
			data->f++;
	}
	return (0);
}
