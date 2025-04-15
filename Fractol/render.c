#include "fractol.h"

double map_rescaled(int px, double min, double max, int screen_size)
{
    return (min + ((double)px / screen_size) * (max - min));
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;

	y = 0;
	while(y < HEIGTH)
	{
		x = 0;
		while(x < WIDTH)
		{
			put_pixel(x, y , fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win, fractal->img->img_ptr, 0, 0);
}
