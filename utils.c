/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <aaghbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:07:28 by aaghbal           #+#    #+#             */
/*   Updated: 2022/10/30 14:00:03 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	c;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	c = ft_strlen(s1);
	p = (char *)malloc((c + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	conv_e(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map2[i][j] == 'E')
				data->map2[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	conv_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map3[i][j] == 'C')
				data->map3[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	cole_len(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map2[i][j] == 'C')
				data->num_col++;
			j++;
		}
		i++;
	}
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
