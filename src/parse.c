/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:29 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/01 20:44:11 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandlebrot.h"
#include "../includes/error.h"
#include "../includes/julia.h"

t_fractol init_window(t_fractol fractol, int height, int width)
{
	fractol.window.height = height;
	fractol.window.width = width;
	fractol.max_iter = 1000;
	fractol.mlx_ptr[0] = mlx_init();
	fractol.mlx_ptr[1] = mlx_init();
	fractol.mlx_ptr[2] = mlx_init();
	fractol.mlx_ptr[3] = mlx_init();
	fractol.win_ptr[0] = mlx_new_window(
		fractol.mlx_ptr,
		fractol.window.width,
		fractol.window.height,
		fractol.name
	);
	fractol.win_ptr[1] = mlx_new_window(
		fractol.mlx_ptr,
		fractol.window.width,
		fractol.window.height,
		fractol.name
	);
	fractol.win_ptr[2] = mlx_new_window(
		fractol.mlx_ptr,
		fractol.window.width,
		fractol.window.height,
		fractol.name
	);
	fractol.win_ptr[3] = mlx_new_window(
		fractol.mlx_ptr,
		fractol.window.width,
		fractol.window.height,
		fractol.name
	);
	return (fractol);
}

void init_mandelbrot(void)
{
	t_fractol fractol;

	fractol.name = "Mandelbrot";
	fractol = init_window(fractol, 400, 700);
	fractol.view.y.min = -1;
	fractol.view.y.max = 1;
	fractol.view.x.min = -2.5;
	fractol.view.x.max = 1;
	display_mandlebrot(fractol);
	mlx_mouse_hook(fractol.win_ptr, &mouse_pressed_zoom, (void *)&fractol);
	mlx_loop(fractol.mlx_ptr);
}

void init_julia(void)
{
	t_fractol fractol;

	fractol.name = "Mandelbrot";
	fractol = init_window(fractol, 400, 700);
	fractol.view.y.min = -1;
	fractol.view.y.max = 1;
	fractol.view.x.min = -2.5;
	fractol.view.x.max = 1;

	mlx_loop_hook(fractol.win_ptr, &run_julia, (void *)&fractol);
	mlx_loop(fractol.mlx_ptr);
}

void init_fractal(int i)
{
	switch(i)
	{
		case 1:
			init_mandelbrot();
			break;
		case 2:
			init_julia();
			break;
	}
}

void parse_fractal(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		init_fractal(1);
	else if (ft_strcmp(str, "julia") == 0)
		init_fractal(2);
	else if (ft_strcmp(str, "other") == 0)
		init_fractal(3);
	else 
		f_error(1);
}