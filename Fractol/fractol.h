
#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "Printf/ft_printf.h"

#define WIDTH 600
#define HEIGTH 600
#define MAX_INT 100
#define MOVE_FACTOR 0.1
#define ZOOM_IN 0.9
#define ZOOM_OUT 1.1
#define KEY_ESC 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_TAB 65289

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
	int 	color_mode;

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
int	is_valid_float(char *str);

/*hooks*/
int	close_fractal(t_fractal *fractal);
int	handle_mouse(int button, int x, int y, t_fractal *fractal);
int	handle_key(int keysym, t_fractal *fractal);

/*render*/
void fractal_render(t_fractal *fractal);
double map_rescaled(int px, double min, double max, int screen_size);
int count_num_interactions(t_fractal *fractal,int x, int y);


/*pixels*/
int		get_color_from_iteration(int i, int max_iter, int color_mode);
void	put_pixel(t_img *img, int x, int y, int color);

/*fractol.c*/
void	fractal_init(t_fractal *fractal);
void	init_values(t_fractal *fractal);


#endif
