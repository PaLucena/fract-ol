/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:15:51 by palucena          #+#    #+#             */
/*   Updated: 2023/08/28 15:21:41 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*ft_get_palettes(void)
{
	static t_palette	array[3];

	array[0]
		= (t_palette){5, 0, {0x212121, 0x757575, 0xE0E0E0, 0xEEEEEE, 0x4C4C4C}};
	array[1]
		= (t_palette){5, 0, {0xC0C0C0, 0x777777, 0x4D4D4D, 0x2A2A2A, 0x000000}};
	array[2]
		= (t_palette){5, 0, {0x610B4B, 0x01A9DB, 0xF4FA58, 0xFE642E, 0xB40404}};


	return (array);
}

int	check_name(char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0 || ft_atoi(name) == 1)
		return (1);
	else if (ft_strncmp(name, "julia", 5) == 0 || ft_atoi(name) == 2)
		return (2);
	else if (ft_strncmp(name, "burningship", 11) == 0 || ft_atoi(name) == 3)
		return (3);
	else
		return (0);
}

void	usage(void)
{
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd("\tArrows -> Move\n", 1);
	ft_putstr_fd("\tScroll -> Zoom\n", 1);
	ft_putstr_fd("\t1/2/3 --> Select between fractal\n", 1);
	ft_putstr_fd("\t4/5/6 --> Change color set\n", 1);
	ft_putstr_fd("\tA/S ----> Activate/Deactivate smooth colors\n", 1);
	ft_putstr_fd("\tZ/X ----> Bigger/Lower iteration max\n", 1);
	ft_putstr_fd("\tJ ------> If in Julia set, ", 1);
	ft_putstr_fd("change 'c' to the mouse coordinates\n", 1);
}

void	error_msg(void)
{
	ft_putstr_fd("\033[31mWrong set of parameters\n", 1);
	ft_putstr_fd("\033[31mAvaliable fractals: ", 1);
	ft_putstr_fd("mandelbrot, julia [x, y], burningship\n", 1);
	exit (0);
}

double	ft_atof(char *str)
{
	int		num;
	double	rest;
	char	*tmp;
	int		i;

	num = ft_atoi(str);
	tmp = ft_strchr(str, '.');
	if (!tmp)
		tmp = ft_strchr(str, ',');
	if (!tmp)
		return (num);
	rest = ft_atoi(&tmp[1]);
	i = 1;
	while (tmp[i])
	{
		rest /= 10;
		i++;
	}
	if (num < 0 || (str[0] == '-' && str[1] == '0'))
		return (num - rest);
	return (num + rest);
}
