/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovis-a <lnovis-a@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:54:45 by lnovis-a          #+#    #+#             */
/*   Updated: 2025/04/17 20:54:46 by lnovis-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal *fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!validate_args(argc, argv, fractal))
	{
		ft_printf("Usage: <julia> <real> <imag> || <mandelbrot>");
		free(fractal);
		exit(1);
	}
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_mouse_hook(fractal->mlx_win, handle_mouse, fractal);
	mlx_key_hook(fractal->mlx_win, handle_key, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, close_fractal, fractal);
	mlx_loop(fractal->mlx_connection);
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
