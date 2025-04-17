#include "fractol.h"

int	close_fractal(t_fractal *fractal)
{
	if (fractal->img)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img->img_ptr);
		free(fractal->img);
	}
	if (fractal->mlx_win)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	if (fractal->mlx_connection)
		mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal);
	exit(0);
	return (0);
}
int	handle_mouse(int button, t_fractal *fractal)
{
	if (button == 4) // scroll up = zoom in
		fractal->zoom *= 0.8;
	else if (button == 5) // scroll down = zoom out
		fractal->zoom *= 1.2;

	fractal_render(fractal);
	return (0);
}
