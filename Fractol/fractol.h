
#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h> // apagar dps
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx/mlx.h"

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
	char	*name;
	//MLX
	void	*mlx_connection; // mlx_init()
	void	*mlx_win; 	 // mlx_new_window()
	//Image
	t_img	img;

	//Hooks member variables //TODO
	double	escape_value; // hypotenuse
	int		iterations_defintion; // value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;


int	ft_strncmp(const char *s1, const char *s2, size_t n);

