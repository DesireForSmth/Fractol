#include "../includes/fractol.h"

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
	//printf("%d\n", data->iteration_max);
	mandelbrot(data);
	/*
	if (data)
		printf("button = %d, x = %d, y = %d\n", button, x, y);
	*/
	return (0);
}
