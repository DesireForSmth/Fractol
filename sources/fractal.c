/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:00:08 by mcarc             #+#    #+#             */
/*   Updated: 2020/03/14 10:00:09 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract(t_fractal *data)
{
	if (data->type == 0)
		mandelbrot(data);
	if (data->type == 1)
		julia(data);
	if (data->type == 2)
		burningship(data);
}
