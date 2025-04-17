#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal = NULL;

	if (!validate_args(argc, argv, fractal))
	{
		help_message();
		return (0);
	}
	fractal_init(fractal);
}


void help_message(void)
{
	ft_printf("<julia> <real> <imag> or <mandelbrot>");
	exit(1);
}

int	validate_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fractal->type = 1;
		fractal->name = argv[1];
		return (1);
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractal->type = 2;
		fractal->name = argv[1];
		fractal->julia_c_re = ft_atof(argv[2]);
		fractal->julia_c_img = ft_atof(argv[3]);
		return (1);
	}
	return (0);
}
