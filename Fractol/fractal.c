#include "fractol.h"

static void malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	t_fractal	fractal;

	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		malloc_error();
	}

	fractal->mlx_win = mlx_new_window(fractal->mlx_connection,WIDTH, HEIGHT, fractal->name);

	if(fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img->img_ptr = mlx_new_image(fractal->mlx_connection,WIDTH, HEIGHT)

	if(fractal->img->img_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img->pixels_ptr = mlx_get_data_addr(fractal->img->img_ptr, &fractal->img->bbp,  &fractal->img->line_len,  &fractal->img->endian )
}
