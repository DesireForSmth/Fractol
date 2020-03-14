/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:23 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/14 10:00:03 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		arg_check(int argc, char *argv, t_fractal *data)
{
	if (argc != 2)
	{
		ft_putendl("Usage: ./fractol \"Mandelbrot\", \"Julia\" or ...");
		return (0);
	}
	else if (!ft_strcmp(argv, "Mandelbrot"))
	{
		data->type = 0;
		mandelbrot_init(data);
		return (1);
	}
	else if (!ft_strcmp(argv, "Julia"))
	{
		data->type = 1;
		julia_init(data);
		return (1);
	}
	else if (!ft_strcmp(argv, "Burningship"))
	{
		data->type = 2;
		return (1);
	}
	ft_putendl("Usage: ./fractol \"Mandelbrot\", \"Julia\" "
			"or \"Burningship\" ");
	return (0);
}

int		data_init(t_fractal *data)
{
	if (!(data->mlx = mlx_init()))
		return (0);
	if (!(data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol")))
	{
		free(data->mlx);
		return (0);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	return (1);
}

void	fractal_init(t_fractal *data)
{
	if (data->type == 0)
		mandelbrot_init(data);
	if (data->type == 1)
		julia_init(data);
	if (data->type == 2)
		burningship_init(data);
}

int		expose_hook(t_fractal *data)
{
	fract(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractal *data;

	if (!(data = (t_fractal *)malloc(sizeof(t_fractal))))
		return (-1);
	if (!arg_check(argc, argv[1], data))
	{
		free(data);
		return (-1);
	}
	data_init(data);
	fractal_init(data);
	mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
	fract(data);
	mlx_key_hook(data->win, keyboard_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
	mlx_loop(data->mlx);
	return (0);
}
