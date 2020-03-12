/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:03:05 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/07 16:03:06 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "pthread.h"
# include "libft/includes/libft.h"
# define WIDTH 1200
# define HEIGHT 900

typedef struct		s_fractal
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				type;
	int				x;
	int				y;
	int				color;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			x1;
	double			y1;
	double			z_tmp;
	double			zoom;
	int				iteration;
	int				iteration_max;
}					t_fractal;

int		arg_check(int argc, char *argv, t_fractal *data);
int		fractal_init(t_fractal *data);
void	mandelbrot(t_fractal *data);

#endif
