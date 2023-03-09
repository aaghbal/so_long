/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:17:17 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/23 22:17:19 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	posplayer(t_data *data)
{
	int	k;
	int	l;

	k = 0;
	while (k < data->map_h)
	{
		l = 0;
		while (l < data->map_w)
		{
			if (data->map[k][l] == 'P')
			{
				data->pla_x = k;
				data->pla_y = l;
				return ;
			}
		l++;
		}
	k++;
	}
}

void	ft_up( t_data *data)
{
	if (data->map[data->pla_x - 1][data->pla_y] == 'C')
	{
		data->map[data->pla_x - 1][data->pla_y] = '0';
		data->num_col2--;
	}
	if (data->map[data->pla_x - 1][data->pla_y] == 'E' && data->num_col2 == 0)
		exit(write(1, "YOU WIN", 7));
	if (data->map[data->pla_x - 1][data->pla_y] == 'N')
		exit(write(1, "YOU LOSE", 10));
	if (data->map[data->pla_x - 1][data->pla_y] != '1' &&
	data->map[data->pla_x - 1][data->pla_y] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->map[data->pla_x][data->pla_y] = '0';
		data->pla_x--;
		data->map[data->pla_x][data->pla_y] = 'P';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		cal_move(data, &data->moves);
	}
}

void	ft_down(t_data *data)
{
	if (data->map[data->pla_x + 1][data->pla_y] == 'C')
	{
		data->map[data->pla_x + 1][data->pla_y] = '0';
		data->num_col2--;
	}
	if (data->map[data->pla_x + 1][data->pla_y] == 'E' && data->num_col2 == 0)
		exit(write(1, "YOU WIN", 7));
	if (data->map[data->pla_x + 1][data->pla_y] == 'N')
		exit(write(1, "YOU LOSE", 8));
	if (data->map[data->pla_x + 1][data->pla_y] != '1' &&
	data->map[data->pla_x + 1][data->pla_y] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->map[data->pla_x][data->pla_y] = '0';
		data->pla_x++;
		data->map[data->pla_x][data->pla_y] = 'P';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		cal_move(data, &data->moves);
	}
}

void	ft_right(t_data *data)
{
	if (data->map[data->pla_x][data->pla_y + 1] == 'C')
	{
		data->map[data->pla_x][data->pla_y + 1] = '0';
		data->num_col2--;
	}
	if (data->map[data->pla_x][data->pla_y + 1] == 'E' && data->num_col2 == 0)
		exit(write(1, "YOU WIN", 7));
	if (data->map[data->pla_x][data->pla_y + 1] == 'N')
		exit(write(1, "YOU LOSE", 8));
	if (data->map[data->pla_x][data->pla_y + 1] != '1' &&
	data->map[data->pla_x][data->pla_y + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->map[data->pla_x][data->pla_y] = '0';
		data->pla_y++;
		data->map[data->pla_x][data->pla_y] = 'P';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		cal_move(data, &data->moves);
	}
}

void	ft_left(t_data *data)
{
	if (data->map[data->pla_x][data->pla_y - 1] == 'C')
	{
		data->map[data->pla_x][data->pla_y - 1] = '0';
		data->num_col2--;
	}
	if (data->map[data->pla_x][data->pla_y - 1] == 'E' && data->num_col2 == 0)
		exit(write(1, "YOU WIN", 7));
	if (data->map[data->pla_x][data->pla_y - 1] == 'N')
		exit(write(1, "YOU LOSE", 8));
	if (data->map[data->pla_x][data->pla_y - 1] != '1' &&
	data->map[data->pla_x][data->pla_y - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->map[data->pla_x][data->pla_y] = '0';
		data->pla_y--;
		data->map[data->pla_x][data->pla_y] = 'P';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		cal_move(data, &data->moves);
	}
}
