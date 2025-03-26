#include "fractol.h"

int main (int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) || argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal->name = argv[1];
		// INICIAR A APLICAÇÃO
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop()

	}
	else
	{
		write(1,"ERROR MESSAGE",13);
		exit(EXIT_FAILURE);
	}
}
