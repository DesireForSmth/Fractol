/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:00:33 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/14 10:00:34 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_julia(int x, int y, t_fractal *data)
{
	if (data->move == 1 && data->type == 1 && data->julia_mouse == 1)
	{
		data->c_r = 725;
		data->c_i = 800;
		data->c_r += (725 - x) / data->zoom * 500;
		data->c_i += (800 - y) / data->zoom * 500;
		fract(data);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fractal *data)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (button == MOUSE_UP)
	{
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.1));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.1));
		data->zoom *= 1.1;
		data->iteration_max += 1;
	}
	else if (button == MOUSE_DOWN)
	{
		data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.1));
		data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.1));
		data->zoom /= 1.1;
		data->iteration_max -= 1;
	}
	fract(data);
	return (0);
}
