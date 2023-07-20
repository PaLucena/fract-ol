/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palucena <palucena@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:38:50 by palucena          #+#    #+#             */
/*   Updated: 2023/07/20 20:20:07 by palucena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 1024
#define HEIGHT 512

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <math.h>
# include "libft/libft.h"
# include "../mlx/mlx.h"

# define ESC_KEY 53

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
}			t_fractol;

void		create_window(t_fractol *fractal);
void		loop(t_fractol *fractal);

#endif