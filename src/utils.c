/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:15:51 by palucena          #+#    #+#             */
/*   Updated: 2023/08/24 13:31:00 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	ft_putstr_fd("\033[31mAvaliable fractals: mandelbrot, julia, burningship\n", 1);
	exit (0);
}

//double		ft_atof(char *nb);
