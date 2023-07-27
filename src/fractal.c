/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:08:36 by palucena          #+#    #+#             */
/*   Updated: 2023/07/26 18:37:42 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal(char	*av, t_info *info)
{
	if (strcmp(av, "mandelbrot") == 0 || strcmp(av, "Mandelbrot") == 0)
		mandelbrot(&info);
	/* else if (strcmp(av, "julia") == 0 || strcmp(av, "Julia") == 0)
		julia(&info);
	else if (strcmp(av, "burningship") == 0 || strcmp(av, "Burningship") == 0)
		burningship(&info); */ // Paso a paso
	else
	{
		ft_putstr_fd("\nError: Wrong arguments\n", 1);
		ft_putstr_fd("Example: ./fractol mandelbrot\n", 1);
	}
}

void	mandelbrot(t_info *info)
{
	
}

// void	julia(t_info *info)  Paso a paso

//void	burningship(t_info *info) Paso a paso