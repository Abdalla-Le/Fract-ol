#include "fractol.h"

static void malloc_error(void)
{
	perror("problems with malloc");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error();

	fractal->mlx_win = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGTH, "Fract-ol");
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img = malloc(sizeof(t_img));
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img->img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGTH);
	if (fractal->img->img_ptr == NULL)
	{
		free(fractal->img);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}

	fractal->img->pixels_ptr = mlx_get_data_addr(
		fractal->img->img_ptr,
		&fractal->img->bpp,
		&fractal->img->line_len,
		&fractal->img->endian
	);
}

