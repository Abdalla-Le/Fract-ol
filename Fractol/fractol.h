
#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> // apagar dps
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "Printf/ft_printf.h"

#define WIDTH 800
#define HEIGTH 800

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	int		type;
	char	*name;
	void	*mlx_connection;
	void	*mlx_win;
	t_img	*img;


	double	escape_value;
	int		max_int;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_c_re;
	double	julia_c_img;
}				t_fractal;

/*main.c*/
void help_message(void);
int	validate_args(int argc, char **argv, t_fractal *fractal);

/*utils.c*/
double	ft_atof(const char *str);

/*hooks*/


/*render*/
void fractal_render(t_fractal *fractal);
double map_rescaled(int px, double min, double max, int screen_size);
int count_num_interactions(t_fractal *fractal,int x, int y);


/*pixels*/
int	get_color_from_iteration(int i, int max_iter);
void	put_pixel(t_img *img, int x, int y, int color);

/*fractol.c*/
void	fractal_init(t_fractal *fractal);
#endif
