/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:02:23 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/07 16:02:24 by mcarc            ###   ########.fr       */
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
		return (1);
	}
	else if (!ft_strcmp(argv, "Julia"))
	{
		data->type = 1;
		return (1);
	}
	else if (!ft_strcmp(argv, "..."))
	{
		data->type = 2;
		return (1);
	}
	ft_putendl("Usage: ./fractol \"Mandelbrot\", \"Julia\" or ...");
	return (0);
}

int		fractal_init(t_fractal *data)
{
	if(!(data->mlx = mlx_init()))
		return (0);
	if(!(data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol")))
	{
		free(data->mlx);
		return (0);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->size_line, &data->endian);
	return (1);
}

int		expose_hook(t_fractal *data)
{
	mandelbrot(data);
	return (0);
}

void	fract(t_fractal *data)
{
	if (data->type == 0)
	{
		mandelbrot_init(data);
		mandelbrot(data);
	}
	if (data->type == 1)
	{
		julia_init(data);
		julia(data);
	}
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
	fractal_init(data);
	ft_putendl("OK");
	fract(data);
	ft_putendl("OK");
	//mlx_expose_hook(data->win, expose_hook, data);
	mlx_key_hook(data->win, keyboard_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop(data->mlx);
	//free(data);
	return (0);
}
