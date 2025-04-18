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
int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= ZOOM_IN;
	else if (button == 5)
		fractal->zoom *= ZOOM_OUT;

	fractal_render(fractal);
	return (0);
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESC)
		close_fractal(fractal);
	else if (keysym == KEY_LEFT)
		fractal->shift_x -= MOVE_FACTOR * fractal->zoom;
	else if (keysym == KEY_RIGHT)
		fractal->shift_x += MOVE_FACTOR * fractal->zoom;
	else if (keysym == KEY_UP)
		fractal->shift_y -= MOVE_FACTOR * fractal->zoom;
	else if (keysym == KEY_DOWN)
		fractal->shift_y += MOVE_FACTOR * fractal->zoom;
	else if (keysym == KEY_TAB)
		fractal->color_mode = (fractal->color_mode + 1) % 4;
	fractal_render(fractal);
	return (0);
}
