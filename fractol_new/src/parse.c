/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:39:20 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/04 18:15:17 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandelbrot.h"

t_program init_program(void)
{
	t_program prog;
	ZOOM = 0;
	HT = 600;
	WT = 800;
	NAME = "Fractol";
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WT, HT, NAME);
	ITER = 500;

	return (prog);
}

void parse_fractal(char *str, t_program prog)
{	
	prog = init_program();
	if (ft_strcmp(str, "mandelbrot") == 0)
		init_mandelbrot(prog);
	// else if (ft_strcmp(str, "julia") == 0)
	// 	init_julia(prog);
	// else if (ft_strcmp(str, "burningship") == 0)
	// 	init_burningship(prog);
	else 
		f_error(1);
}