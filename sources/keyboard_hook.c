/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:00:21 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/14 10:00:22 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fractal_shift(int keycode, t_fractal *data)
{
	if (keycode == 123)
		data->x1 += (1 / data->zoom * 5);
	else if (keycode == 124)
		data->x1 -= (1 / data->zoom * 5);
	else if (keycode == 126)
		data->y1 += (1 / data->zoom * 5);
	else
		data->y1 -= (1 / data->zoom * 5);
	return (0);
}

int		color_change(int keycode, t_fractal *data)
{
	if (keycode == 18)
		data->color = 2060;
	else if (keycode == 19)
		data->color = 265;
	else if (keycode == 20)
		data->color = 0xab7c3f;
	else if (keycode == 21)
		data->color = 0x1a001a;
	else if (keycode == 22)
		data->color = 0x406bab;
	else if (keycode <= 126 && keycode >= 123)
		fractal_shift(keycode, data);
	else
		return (0);
	fract(data);
	return (1);
}

int		type_change(int keycode, t_fractal *data)
{
	if (keycode == 38)
	{
		data->type = 1;
		fractal_init(data);
		fract(data);
	}
	if (keycode == 46)
	{
		data->type = 0;
		fractal_init(data);
		fract(data);
	}
	if (keycode == 11)
	{
		data->type = 2;
		fractal_init(data);
		fract(data);
	}
	return (0);
}

int		keyboard_hook(int keycode, t_fractal *data)
{
	if (color_change(keycode, data))
		return (0);
	if (keycode == 15)
	{
		fractal_init(data);
		fract(data);
	}
	if (keycode == 38 || keycode == 46 || keycode == 11)
		type_change(keycode, data);
	if (keycode == KEY_SPACE)
		data->move *= -1;
	if (keycode == 53)
		exit(1);
	return (0);
}
