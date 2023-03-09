/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:08:17 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/23 22:08:19 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_data *data)
{
	ft_count2(data);
	ft_exit (keycode);
	if (keycode == 13)
		ft_up(data);
	if (keycode == 1)
		ft_down(data);
	if (keycode == 0)
		ft_left(data);
	if (keycode == 2)
		ft_right(data);
	return (0);
}

void	initia_image(t_data *data)
{
	int	i;

	i = 0;
	data->win = mlx_new_window(data->mlx, data->map_w * 32,
			data->map_h * 32, "so_long");
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &i, &i);
	if (!data->img.wall)
		exit(write(1, "Error\nimage error!", 18));
	data->img.colec = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin1.xpm", &i, &i);
	if (!data->img.colec)
		exit(write(1, "Error\nimage error!", 18));
	data->img.fr_spac = mlx_xpm_file_to_image(data->mlx,
			"./textures/free.xpm", &i, &i);
	if (!data->img.fr_spac)
		exit(write(1, "Error\nimage error!", 18));
	data->img.exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/dor.xpm", &i, &i);
	if (!data->img.exit)
		exit(write(1, "Error\nimage error!", 18));
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &i, &i);
	if (!data->img.player)
		exit(write(1, "Error\nimage error!", 18));
}

void	put_image(t_data *data)
{
	data->x = 0;
	while (data->x < data->map_h)
	{
		data->y = 0;
		while (data->y < data->map_w)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.fr_spac, data->y * 32, data->x * 32);
			if (data->map[data->x][data->y] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.wall, data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.player, data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.exit, data->y * 32, data->x * 32);
			else if (data->map[data->x][data->y] == 'N')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.enemy, data->y * 32, data->x * 32);
			data->y++;
		}
		data->x++;
	}
}

void	copy_map(int fd, t_data *data)
{
	char	*gnl;

	data->map[0] = get_next_line(fd);
	data->map2[0] = data->map[0];
	data->map3[0] = data->map[0];
	gnl = ft_strdup(data->map[0]);
	data->map_w = ft_strlen(data->map[0]);
	while (gnl)
	{
		data->map_h++;
		free(gnl);
		gnl = get_next_line(fd);
		data->map[data->map_h] = ft_strdup(gnl);
		data->map2[data->map_h] = ft_strdup(gnl);
		data->map3[data->map_h] = ft_strdup(gnl);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	data = malloc (sizeof(t_data));
	data->moves = 0;
	norm(argc, data);
	if (!check_exten(argv[1]))
		exit(write(1, "Error\nerror extention!", 22));
	if (fd < 0)
		exit(write(1, "error\nerror map file!", 21));
	copy_map(fd, data);
	posplayer(data);
	if (!checkligne(data) || !checkwall(data)
		|| !checkchar(data) || !check_validchar(data))
		exit(write(1, "Error\nerror map!", 16));
	if (!checkpath_ex(data->pla_x, data->pla_y, data)
		|| !checkpath_col(data->pla_x, data->pla_y, data))
		exit(write(1, "Error\nerror map!", 16));
	data->mlx = mlx_init();
	initia_image(data);
	intial_ene(data);
	initial_var(data);
	mlx_loop(data->mlx);
}
