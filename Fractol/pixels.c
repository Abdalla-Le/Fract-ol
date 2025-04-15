#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*offseat;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGTH)
		return ;

	offseat = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));


	if (img->endian == 0)
	{
		// Little Endian
		offseat[0] = color & 0xFF;
		offseat[1] = (color >> 8) & 0xFF;
		offseat[2] = (color >> 16) & 0xFF;
	}
	else
	{
		// Big Endian
		offseat[0] = (color >> 16) & 0xFF;
		offseat[1] = (color >> 8) & 0xFF;
		offseat[2] = color & 0xFF;
	}
}
int	get_color_from_iteration(int i, int max_iter)
{
	if (i == max_iter)
		return (0x000000);

	int	r = (i * 9) % 256;
	int	g = (i * 2) % 256;
	int	b = (i * 5) % 256;

	return (r << 16 | g << 8 | b);
}
