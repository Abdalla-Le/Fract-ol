/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:55:11 by lnovis-a          #+#    #+#             */
/*   Updated: 2025/04/17 20:58:15 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void malloc_error(void)
{
	ft_putstr_fd("problems with malloc", 2);
	exit(EXIT_FAILURE);
}

static void	init_img(t_fractal *fractal)
{
	fractal->img = malloc(sizeof(t_img));
	if (!fractal->img)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img->img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGTH);
	if (!fractal->img->img_ptr)
	{
		free(fractal->img);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img->pixels_ptr = mlx_get_data_addr(fractal->img->img_ptr,
			&fractal->img->bpp, &fractal->img->line_len, &fractal->img->endian);
}

void init_values(t_fractal *fractal)
{
	fractal->max_int = MAX_INT;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1.0;
}
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGTH, "Fract-ol");
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	init_img(fractal);
	init_values(fractal);
}

