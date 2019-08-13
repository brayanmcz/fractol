/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:08:31 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/12 18:23:33 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/mandelbrot.h"
# define PARAMS(chunk) (void *)&prog, (void*)chunk

int	createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int	calc_color(int iter, int max_iter)
{
	long double t;
	int r;
	int g;
	int b;

	t = (long double)iter / (long double)max_iter;
	r = (9*(1-t)*t*t*t*255);
	g = (15*(1-t)*(1-t)*t*t*255);
	b = (8.5*(1-t)*(1-t)*(1-t)*t*255);
	return (createRGB(r, g, b));
}

int	mandelbrot_test(t_program prog)
{
	long double rsqr = 0;
	long double isqr = 0;
	long double zsqr = 0;

	int iter = 0;
	long double x = 0;
	long double y = 0;
	while (rsqr + isqr <= 4 && iter < prog.max_iter)
	{
		x = rsqr - isqr + prog.win.vx;
		y = zsqr - rsqr - isqr + prog.win.vy;
		rsqr = x * x;
		isqr = y * y;
		zsqr = (x + y) * (x + y);
		iter++;
	}
	return (calc_color(iter, prog.max_iter));
}

void	*display_mandelbrot_chunk(void *params)
{
	t_program			prog;
	void				**param;
	unsigned int		count_w;
	unsigned int		count_h;
	int					start;

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
	return (param[0]);
}

void display_mandelbrot(t_program prog)
{
	// printf("minX: %Lf, maxX: %Lf, minX: %Lf, maxY: %Lf\n", prog.view.x.min, prog.view.x.max, prog.view.y.min, prog.view.y.max);

	prog.win.dx = (long double)(prog.view.x.max - prog.view.x.min) / (long double)prog.win.width;
	prog.win.dy = (long double)(prog.view.y.max - prog.view.y.min) / (long double)prog.win.height;

	pthread_t thread[4];
	pthread_create(&thread[0], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(0)});
	pthread_create(&thread[1], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(1)});
	pthread_create(&thread[2], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(2)});
	pthread_create(&thread[3], NULL, display_mandelbrot_chunk, (void *[2]){PARAMS(3)});
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}

int mouse_pressed_zoom(int button, int x, int y, void *param)
{
	// printf("x: %d, y: %d\n", x, y);

	t_program *prog;
	prog = (t_program *)param;

	// mlx_destroy_image(prog->mlx_ptr, prog->image.ptr);
	// mlx_clear_window(prog->mlx_ptr, prog->win_ptr);

	// prog->image.ptr = mlx_new_image(prog->mlx_ptr, prog->win.width, prog->win.height);
	// prog->image.data = (int *)mlx_get_data_addr(prog->image.ptr,
	// 											&prog->image.bits_per_pixel,
	// 											&prog->image.width_len,
	// 											&prog->image.endian);

	button = button + 1;
		prog->win.dx = (long double)(prog->view.x.max - prog->view.x.min) / (long double)prog->win.width;
	prog->win.dy = (long double)(prog->view.y.max - prog->view.y.min) / (long double)prog->win.height;
	long double center_x = prog->view.x.min + (long double)((long double)x * prog->win.dx);
	long double center_y = prog->view.y.min + (long double)((long double)y * prog->win.dy);

	// printf("dX: %Lf, dY: %Lf, cX: %Lf, cY: %Lf \n", prog->win.dx, prog->win.dy, center_x, center_y);

	long double x_diff = prog->view.x.max - prog->view.x.min;
	long double y_diff = prog->view.y.max - prog->view.y.min;

	x_diff *= 0.9;
	y_diff *= 0.9;
 
	prog->view.y.max = center_y + (y_diff / 2);
	prog->view.y.min = center_y - (y_diff / 2);
	prog->view.x.max = center_x + (x_diff / 2);
	prog->view.x.min = center_x - (x_diff / 2);

	display_mandelbrot(*prog);
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->image.ptr, 0, 0);

	return (x);
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
	prog.view.x.min = -2;
	prog.view.x.max = 1;
	prog.view.y.min = -1;
	prog.view.y.max = 1;

	display_mandelbrot(prog);
	mlx_put_image_to_window(prog.mlx_ptr, prog.win_ptr, prog.image.ptr, 0, 0);
	mlx_mouse_hook(prog.win_ptr, &mouse_pressed_zoom, (void *)&prog);
	mlx_loop(prog.mlx_ptr);
}
