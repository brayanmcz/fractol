/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:08:31 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/04 18:07:52 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandelbrot.h"
#include "../includes/example.h"

// void color_pixel(int *img, int x, int y, int color, int size_line, int bpp)

// }

void init_mandelbrot(t_program prog)
{
    prog.max_iter = 0;
    t_mlx	mlx;
	unsigned int		count_w;
	unsigned int		count_h;

	count_h = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WT, HT, "A simple example");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WT, HT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);
	while (++count_h < HT)
	{
		count_w = -1;
		while (++count_w < WT)
		{
			if (count_w % 2)
				mlx.img.data[count_h * WT + count_w] = 0x00FF00;
			else
				mlx.img.data[count_h * WT + count_w] = 0xFFFFFF;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}