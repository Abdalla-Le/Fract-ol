/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:54:49 by lnovis-a          #+#    #+#             */
/*   Updated: 2025/04/17 20:54:50 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*offseat;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;

	offseat = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));


	if (img->endian == 0)
	{
		offseat[0] = color & 0xFF;
		offseat[1] = (color >> 8) & 0xFF;
		offseat[2] = (color >> 16) & 0xFF;
	}
	else
	{
		offseat[0] = (color >> 16) & 0xFF;
		offseat[1] = (color >> 8) & 0xFF;
		offseat[2] = color & 0xFF;
	}
}
int	get_color_from_iteration(int i, int max_iter, int color_mode)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	if (i == max_iter)
		return (0x000000);
	if (color_mode == 0)
	{
		r = (i * 0) % 256;
		g = (i * 5) % 256;
		b = (i * 5) % 256;
	}
	else if (color_mode == 1)
	{
		r = (i * 10) % 256;
		g = (i * 10) % 256;
		b = (i * 0) % 256;
	}
	else
	{
		r = (i * 10) % 256;
		g = (i * 0) % 256;
		b = (i * 1) % 256;
	}
	return (r << 16 | g << 8 | b);
}
