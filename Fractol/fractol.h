
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
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bpp; // bits por pixel
	int		endian;
	int		line_len;
}				t_img;


/*
 * FRACTAL ID
 * ~ MLX stuff
 * ~ Image
 * ~ Hooks values
*/
typedef struct	s_fractal
{
	int	type;
	char	*name;
	//MLX
	void	*mlx_connection; // mlx_init()
	void	*mlx_win; 	 // mlx_new_window()
	//Image
	t_img	*img;

	//Hooks member variables //TODO
	double	escape_value; // hypotenuse
	int		iterations_defintion; // value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_c_re;
	double	julia_c_img;
}				t_fractal;


typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_win;
	t_img	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		type; // 1: Mandelbrot, 2: Julia
	char	*name;
	double	c_re;
	double	c_im;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		max_iter;
}	t_fractol;
/*main.c*/
void help_message(void);
int	validate_args(int argc, char **argv, t_fractal *fractal);

/*utils.c*/
double	ft_atof(const char *str);
#endif
