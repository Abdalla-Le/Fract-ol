/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:45:58 by lnovis-a          #+#    #+#             */
/*   Updated: 2025/04/16 16:46:20 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map_rescaled(int px, double min, double max, int screen_size)
{
    return (min + ((double)px / screen_size) * (max - min));
}

void fractal_render(t_fractal *fractal)
{
	int x;
	int y;
	int i;
	int color;

	y = 0;
	while(y < HEIGTH)
	{
		x = 0;
		while(x < WIDTH)
		{
			i = count_num_interactions(fractal, x, y);
			color = get_color_from_iteration(i, fractal->max_int);
			put_pixel(fractal->img, x, y,color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win,\
		fractal->img->img_ptr, 0, 0);
}
int count_num_interactions(t_fractal *fractal,int x, int y)
{
	double c_re_x;
	double c_img_y;
	double z_re_x;
	double z_img_y;
	int i;

	i = 0;
	c_img_y = 0.0;
	c_re_x = 0.0;
	if (fractal->type == 1)
	{
		c_re_x = map_rescaled(c_re_x, fractal->shift_x - fractal->zoom, fractal->shift_x + fractal->zoom, WIDTH);
		c_img_y = map_rescaled(c_img_y, fractal->shift_y - fractal->zoom, fractal->shift_y + fractal->zoom, HEIGTH);
	}
	else if (fractal->type == 2)
	{
		c_re_x = fractal->julia_c_re;
		c_img_y = fractal->julia_c_img;
		z_re_x = map_rescaled(x, fractal->shift_x - fractal->zoom, fractal->shift_x + fractal->zoom, WIDTH);
		z_img_y = map_rescaled(y, fractal->shift_y - fractal->zoom, fractal->shift_y + fractal->zoom, HEIGTH);
	}
	while ((z_re_x * z_re_x )+ (z_img_y * z_img_y)<= 4 && i < fractal->max_int) {
		double z_re_tmp = z_re_x;
		z_re_x = z_re_x * z_re_x - z_img_y * z_img_y + c_re_x;
		z_img_y = 2 * z_re_tmp * z_img_y + c_img_y;
		i++;
	}
	return (i);
}
