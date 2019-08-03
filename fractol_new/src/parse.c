/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:39:20 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/02 17:09:55 by bcastro          ###   ########.fr       */
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
}

void parse_fractal(char *str, t_program prog)
{
	t_program prog;
	
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