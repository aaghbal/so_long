/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghbal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:19:52 by aaghbal           #+#    #+#             */
/*   Updated: 2023/02/21 15:19:54 by aaghbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(int keycode)
{
	if (keycode == 53)
		exit(write(1, "game over", 9));
	return (0);
}

int	ft_esc(void)
{
	exit(write(1, "game over", 9));
	return (0);
}

int	check_exten(char *argv)
{
	int		i;
	int		j;
	int		len;
	char	*tab;

	tab = ".ber";
	j = 0;
	len = ft_strlen(argv);
	i = len - 4;
	while (argv[i] != '\0')
	{
		if (argv[i] != tab[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
