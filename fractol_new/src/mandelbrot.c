/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:08:31 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/05 15:55:25 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandelbrot.h"
# define PARAMS(chunk) (void *)&prog, (void*)chunk

// void color_pixel(int *img, int x, int y, int color, int size_line, int bpp)
// }

void mandelbrot_test(t_program prog)
{
	long double rsqr;
	long double isqr;
	long double zsqr;

	// int iter = 0;
	// long double = 0;
	// long 
}

void *display_mandelbrot_chunk(void *params)
{
	unsigned int		count_w;
	unsigned int		count_h;
	int					start;
	t_program			prog;
	void				**param;

	param = params;
	prog = *(t_program *)param[0];
	start = (HT / 4) * (int)param[1];
	count_h = start - 1;
	while (++count_h < start + (HT / 4))
	{
		count_w = -1;
		while (++count_w < WT)
		{
			if (count_w % 2)
				prog.image.data[count_h * WT + count_w] = 0x00FF00;
			else
				prog.image.data[count_h * WT + count_w] = 0xFFFFFF;
			mandelbrot_test()
		}
	}
	return(param[0]);
}

void display_mandelbrot(t_program prog)
{
	pthread_t thread[4];

	pthread_create(&thread[0], NULL,
					display_mandelbrot_chunk, (void *[2]){PARAMS(0)});
	pthread_create(&thread[1], NULL,
					display_mandelbrot_chunk, (void *[2]){PARAMS(1)});
	pthread_create(&thread[2], NULL,
					display_mandelbrot_chunk, (void *[2]){PARAMS(2)});
	pthread_create(&thread[3], NULL,
					display_mandelbrot_chunk, (void *[2]){PARAMS(3)});
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}

void init_mandelbrot(t_program prog)
{
	prog.max_iter = 100;
	prog.mlx_ptr = mlx_init();
	prog.win_ptr = mlx_new_window(prog.mlx_ptr, WT, HT, "Fractol");
	prog.image.ptr = mlx_new_image(prog.mlx_ptr, WT, HT);
	prog.image.data = (int *)mlx_get_data_addr(prog.image.ptr,
												&prog.image.bits_per_pixel,
												&prog.image.width_len,
												&prog.image.endian);

	display_mandelbrot(prog);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, prog.image.ptr, 0, 0);
	mlx_loop(prog.mlx_ptr);
}