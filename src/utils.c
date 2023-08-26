/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:15:51 by palucena          #+#    #+#             */
/*   Updated: 2023/08/26 19:33:40 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*ft_get_palettes(void)
{
	static t_palette	array[3];

	array[0]
		= (t_palette){5, 0, {0x757575, 0xE0E0E0, 0xEEEEEE, 0xFAFAFA, 0x212121}};
	array[1]
		= (t_palette){5, 0, {0x000000, 0x004D40, 0x33691E, 0x33691E, 0xF57F17}};
	array[2]
		= (t_palette){5, 0, {0xDAF7A6, 0xFFC300, 0xFF5733, 0xC70039, 0x900C3F}};
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
