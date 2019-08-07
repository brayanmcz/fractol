/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:08:31 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/07 00:10:25 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandelbrot.h"
# define PARAMS(chunk) (void *)&prog, (void*)chunk

// void color_pixel(int *img, int x, int y, int color, int size_line, int bpp)
// }

int createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int calc_color(int iter, int max_iter)
{
	long double t;
	int r;
 	int g;
 	int b;

 	t = (long double)iter / (long double)max_iter;
	r = (9*(1-t)*t*t*t*255);
 	g = (15*(1-t)*(1-t)*t*t*255);
 	b = (8.5*(1-t)*(1-t)*(1-t)*t*255);
	return (createRGB(r,g,b));
}

int mandelbrot_test(t_program prog)
{
	long double rsqr, isqr, zsqr, x, y;
	int iter, color;

	rsqr = 0;
	isqr = 0;
	zsqr = 0;
	iter = 0;
	x = 0;
	y = 0;

	while(rsqr + isqr <= 4 && iter < prog.max_iter)
	{
		x = rsqr - isqr + prog.win.vx;
		y = zsqr - rsqr - isqr + prog.win.vy;
		rsqr = x * x;
		isqr = y * y;
		zsqr = (x + y)*(x + y);
		iter++;
	}
	color = calc_color(iter, prog.max_iter);
	return (color);
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
				prog.win.vx = prog.view.x.min + (count_w * prog.win.dx);
				prog.win.vy = prog.view.y.min + (count_h * prog.win.dy);
				prog.image.data[count_h * WT + count_w] = mandelbrot_test(prog);
		}
	}
	return(param[0]);
}

void display_mandelbrot(t_program prog)
{
	pthread_t thread[4];

	prog.win.dx = (long double)(prog.view.x.max - prog.view.x.min) / (long double)prog.win.width;
	prog.win.dy = (long double)(prog.view.y.max - prog.view.x.min) / (long double)prog.win.height;
	printf("test: %d, %d \n", prog.win.width, prog.win.height);
	prog.win.vy = prog.view.y.min;
	prog.win.vx = prog.view.x.min;
	pthread_create(&thread[0], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(0)});
	pthread_create(&thread[1], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(1)});
	pthread_create(&thread[2], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(2)});
	pthread_create(&thread[3], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(3)});
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
	prog.view.x.min = -2.5;
	prog.view.x.max = 1;
	prog.view.y.min = -1.5;
	prog.view.y.max = 1;

	display_mandelbrot(prog);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, prog.image.ptr, 0, 0);
	mlx_loop(prog.mlx_ptr);
}