#include "../includes/fractol.h"

int		keyboard_hook(int keycode, t_fractal *data)
{
	if (keycode == KEY_SPACE)
	{
		mandelbrot_init(data);
		mandelbrot(data);
	}
	return (0);
}
