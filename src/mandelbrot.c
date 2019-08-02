/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:05:52 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/01 15:19:53 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
# define PARAMS(chunk, thread) (void *)&frac, (void*)chunk, (void*)thread

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

void fractol_test(int Px, int Py, t_fractol fractol, int thread)
{
	long double rsquare = 0;
	long double isquare = 0;
	long double zsquare = 0;

	fractol.iter[thread] = 0;
	fractol.x[thread] = 0;
	fractol.y[thread] = 0;
	while (rsquare + isquare <= 4  &&  fractol.iter[thread] < fractol.max_iter)
	{
		fractol.x[thread] = rsquare - isquare + fractol.mbrot.val_x[thread];
		fractol.y[thread] = zsquare - rsquare - isquare + fractol.mbrot.val_y[thread];
		rsquare = fractol.x[thread]*fractol.x[thread];
		isquare = fractol.y[thread]*fractol.y[thread];
		zsquare = (fractol.x[thread] + fractol.y[thread])*(fractol.x[thread] + fractol.y[thread]);
		fractol.iter[thread]++;
	}
	int color = calc_color(fractol.iter[thread], fractol.max_iter);
	mlx_pixel_put(fractol.mlx_ptr, fractol.win_ptr, Px, Py, color);
}

void *display_mandlebrot_chunk(void *param)
{
	t_fractol *frac;
	void **params;
	unsigned int w_iter;
	unsigned int h_iter;
	unsigned int thread;

	params = param;
	frac = (t_fractol *)params[0];
	h_iter = (unsigned int)params[1];
	thread = (unsigned int)params[2];
	while (h_iter < (unsigned int)params[1] + 100)
	{
		w_iter = 0;
		while (w_iter < frac->window.width)
		{
			frac->mbrot.val_x[thread] = frac->view.x.min + (w_iter * frac->mbrot.x_delta);
			frac->mbrot.val_y[thread] = frac->view.y.min + (h_iter * frac->mbrot.y_delta);
			fractol_test(w_iter, h_iter, *frac, thread);
			w_iter++;
		}
		h_iter++;
	}
	return (frac);
}

t_fractol	display_mandlebrot(t_fractol frac)
{
	pthread_t thread_id[4];

	frac.mbrot.x_delta = (frac.view.x.max - frac.view.x.min) /
	(long double)frac.window.width;
	frac.mbrot.y_delta = (frac.view.y.max - frac.view.y.min) /
	(long double)frac.window.height;
	frac.mbrot.val_y[0] = frac.view.y.min;
	frac.mbrot.val_y[1] = frac.view.y.min;
	frac.mbrot.val_y[2] = frac.view.y.min;
	frac.mbrot.val_y[3] = frac.view.y.min;

	pthread_create(&thread_id[0], NULL, &display_mandlebrot_chunk, (void*[3]){PARAMS(0, 0)});
	pthread_create(&thread_id[1], NULL, &display_mandlebrot_chunk, (void*[3]){PARAMS(100, 1)});
	pthread_create(&thread_id[2], NULL, &display_mandlebrot_chunk, (void*[3]){PARAMS(200, 2)});
	pthread_create(&thread_id[3], NULL, &display_mandlebrot_chunk, (void*[3]){PARAMS(300, 3)});

	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
	pthread_join(thread_id[2], NULL);
	pthread_join(thread_id[3], NULL);

	return (frac);
}

int mouse_pressed_zoom(int button, int x, int y, void *param)
{
	button = button + 1;
	x = x + 1;
	y = y+1;
	t_fractol *fractol;
	fractol = (t_fractol *)param;
	long double center_x = fractol->view.x.min + (long double)((long double)x * fractol->mbrot.x_delta);
	long double center_y = fractol->view.y.min + (long double)((long double)y * fractol->mbrot.y_delta);

	long double x_diff = fractol->view.x.max - fractol->view.x.min;
	long double y_diff = fractol->view.y.max - fractol->view.y.min;

	x_diff *= 0.9;
	y_diff *= 0.9;

	fractol->view.y.max = center_y + (y_diff / 2);
	fractol->view.y.min = center_y - (y_diff / 2);
	fractol->view.x.max = center_x + (x_diff / 2);
	fractol->view.x.min = center_x - (x_diff / 2);


	*fractol = display_mandlebrot(*fractol);

	return (x);
}