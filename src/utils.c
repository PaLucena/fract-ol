/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:12:56 by palucena          #+#    #+#             */
/*   Updated: 2023/08/23 14:33:50 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_args(int ac, char *fr)
{
	int	f;

	if (ac != 2)
	{
		if (ac != 4)
			exit (1);
	}
	if (strcmp(fr, "mandelbrot") == 0 || strcmp(fr, "1"))
		f = 1;
	else if (strcmp(fr, "julia") == 0 || strcmp(fr, "Julia") == 0 || strcmp(fr, "2"))
		f = 2;
	/* else if (strcmp(fr, "burningship") == 0 || strcmp(fr, "Burningship") == 0)
		f = 3; */ // Paso a paso
	else
		exit (1);
	return (f);
}

// double	ft_atof(char *nb)
