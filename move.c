/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:41:15 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/20 17:41:17 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		data->num_col--;
	}
	if (data->map[data->pla_x - 1][data->pla_y] == 'E' && data->num_col == 0)
		exit(write(1, "game finish", 11));
	if (data->map[data->pla_x - 1][data->pla_y] != '1' &&
	data->map[data->pla_x - 1][data->pla_y] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->pla_x--;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		write(1, "moves :", 7);
		ft_putnbr(data->moves);
		write(1, "\n", 1);
	}
}

void	ft_down(t_data *data)
{
	if (data->map[data->pla_x + 1][data->pla_y] == 'C')
	{
		data->map[data->pla_x + 1][data->pla_y] = '0';
		data->num_col--;
	}
	if (data->map[data->pla_x + 1][data->pla_y] == 'E' && data->num_col == 0)
		exit(write(1, "game finish", 11));
	if (data->map[data->pla_x + 1][data->pla_y] != '1' &&
	data->map[data->pla_x + 1][data->pla_y] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->pla_x++;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
			data->moves++;
		write(1, "moves :", 7);
		ft_putnbr(data->moves);
		write(1, "\n", 1);
	}
}

void	ft_right(t_data *data)
{
	if (data->map[data->pla_x][data->pla_y + 1] == 'C')
	{
		data->map[data->pla_x][data->pla_y + 1] = '0';
		data->num_col--;
	}
	if (data->map[data->pla_x][data->pla_y + 1] == 'E' && data->num_col == 0)
		exit(write(1, "game finish", 11));
	if (data->map[data->pla_x][data->pla_y + 1] != '1' &&
	data->map[data->pla_x][data->pla_y + 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->pla_y++;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		write(1, "moves :", 7);
		ft_putnbr(data->moves);
		write(1, "\n", 1);
	}
}

void	ft_left(t_data *data)
{
	if (data->map[data->pla_x][data->pla_y - 1] == 'C')
	{
		data->map[data->pla_x][data->pla_y - 1] = '0';
		data->num_col--;
	}
	if (data->map[data->pla_x][data->pla_y - 1] == 'E' && data->num_col == 0)
		exit(write(1, "game finish", 11));
	if (data->map[data->pla_x][data->pla_y - 1] != '1' &&
	data->map[data->pla_x][data->pla_y - 1] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		data->pla_y--;
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.fr_spac, data->pla_y * 32, data->pla_x * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, data->pla_y * 32, data->pla_x * 32);
		data->moves++;
		write(1, "moves :", 7);
		ft_putnbr(data->moves);
		write(1, "\n", 1);
	}
}
