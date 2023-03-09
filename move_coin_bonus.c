/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:28:24 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/25 17:28:26 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	intial_ene(t_data *data)
{
	int	i;

	data->img.enemy = mlx_xpm_file_to_image(data->mlx,
			"./textures/ene1.xpm", &i, &i);
	if (!data->img.enemy)
		exit(write(1, "Error\nimage error!", 18));
	data->img.enemy1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/ene2.xpm", &i, &i);
	if (!data->img.enemy1)
		exit(write(1, "Error\nimage error!", 18));
}

void	move_coin(t_data *data)
{
	int	i;

	if (data->imgag_frams == 2)
	{
		data->img.colec = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin1.xpm", &i, &i);
		data->imgag_frams++;
	}
	else if (data->imgag_frams == 4)
	{
		data->img.colec = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin3.xpm", &i, &i);
		data->imgag_frams = 0;
	}
	else if (data->imgag_frams == 0)
	{
		data->img.colec = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin5.xpm", &i, &i);
		data->imgag_frams++;
	}
	else
		data->imgag_frams++;
}
