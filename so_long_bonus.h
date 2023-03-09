/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:15:30 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/23 22:15:32 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "get_next_line.h" 
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_components
{
	void	*wall;
	void	*player;
	void	*colec;
	void	*exit;
	void	*fr_spac;
	void	*enemy;
	void	*enemy1;
}	t_comp;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map[300000];
	char	*map2[300000];
	char	*map3[300000];
	int		map_w;
	int		map_h;
	int		pla_x;
	int		pla_y;
	int		en_x;
	int		en_y;
	int		num_col;
	int		num_col2;
	int		x;
	int		y;
	int		flag;
	int		moves;
	t_comp	img;
	int		dir;
	int		f;
	int		frams;
	int		imgag_frams;
}	t_data;

char	*ft_strdup(const char *s1);
int		checkligne(t_data *data);
int		checkwall(t_data *data);
int		checkchar(t_data *data);
int		check_validchar(t_data *data);
void	posplayer(t_data *data);
int		checkpath_ex(int x, int y, t_data *data);
int		checkpath_col(int x, int y, t_data *data);
void	check(int *p1, int x, int y, t_data *data);
void	check(int *p2, int x, int y, t_data *data);
void	helper(int x, int y, int *col, t_data *data);
void	conv_e(t_data *data);
void	conv_c(t_data *data);
void	cole_len(t_data *data);
void	ft_up( t_data *data);
void	ft_down( t_data *data);
void	ft_left( t_data *data);
void	ft_right( t_data *data);
int		ft_putstr(const char *s);
void	ft_putnbr(int n);
void	helper2(int x, int y, int *col, t_data *data);
void	ft_count(t_data *data);
int		ft_exit(int keycode);
int		check_exten(char *argv);
int		ft_esc(void);
void	norm(int arg, t_data *data);
char	*ft_itoa(int n);
void	cal_move(t_data *data, int *p);
///
int		move_ene(t_data *data);
void	posenemy(t_data *data);
void	ft_count2(t_data *data);
void	cole_len2(t_data *data);
void	initial_var(t_data *data);
int		key_hook(int keycode, t_data *data);
void	put_image(t_data *data);
int		move_col(t_data *data);
void	move_coin(t_data *data);
void	intial_ene(t_data *data);
////

#endif
