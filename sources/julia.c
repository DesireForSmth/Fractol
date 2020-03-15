/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:00:13 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/14 10:00:15 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_fractal *data)
{
	data->iteration_max = 50;
	data->zoom = 250;
	data->x1 = -2.3;
	data->y1 = -1.9;
	data->color = 2060;
	data->c_r = 725;
	data->c_i = 800;
	data->julia_mouse = 1;
	data->move = 1;
	data->type = 1;
}

void	julia_pxl(t_fractal *data)
{
	data->z_r = (double)(data->x / data->zoom) + data->x1;
	data->z_i = (double)(data->y / data->zoom) + data->y1;
	data->iteration = 0;
	if (data->iteration_max > 150)
		data->iteration_max = 150;
	while (data->z_r * data->z_r + data->z_i
		* data->z_i < 4 && data->iteration < data->iteration_max)
	{
		data->z_tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
					data->z_i * data->z_i - 0.4 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->z_tmp + data->c_i / WIDTH;
		data->iteration++;
	}
	if (data->iteration == data->iteration_max)
		put_pxl_to_img(data, data->x, data->y, data->color);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->iteration));
}

void	*julia_iter(void *line)
{
	t_fractal	*data;
	int			y_tmp;

	data = (t_fractal *)line;
	data->x = 0;
	y_tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = y_tmp;
		while (data->y < data->y_max)
		{
			julia_pxl(data);
			data->y++;
		}
		data->x++;
	}
	return (line);
}

void	julia_thread(t_fractal *data)
{
	t_fractal	tab[THREADS];
	pthread_t	thread[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractal));
		tab[i].y = LINE_HEIGHT * i;
		tab[i].y_max = LINE_HEIGHT * (i + 1);
		pthread_create(&thread[i], NULL, julia_iter, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
							0, 0);
}

void	julia(t_fractal *data)
{
	julia_thread(data);
}
