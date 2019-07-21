/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:34:08 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/20 18:38:53 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

 	t = (long double)iter / (long double) max_iter;
	r = (9*(1-t)*t*t*t*255);
 	g = (15*(1-t)*(1-t)*t*t*255);
 	b = (8.5*(1-t)*(1-t)*(1-t)*t*255);
	return (createRGB(r,g,b));
}

void fractol_test(int Px, int Py, long double x0, long double y0, t_fractol fractol)
{
	long double rsquare = 0;
	long double isquare = 0;
	long double zsquare = 0;
	int iteration = 0;
	long double x = 0;
	long double y = 0;
	
	while (rsquare + isquare <= 4  &&  iteration < fractol.max_iter)
	{
		x = rsquare - isquare + x0;
		y = zsquare - rsquare - isquare + y0;
		rsquare = x*x;
		isquare = y*y;
		zsquare = (x + y)*(x + y);
		iteration++;
	}

	int color = calc_color(iteration, fractol.max_iter);

	mlx_pixel_put(fractol.mlx_ptr, fractol.win_ptr, Px, Py, color);
}

/*
** Initialize the Window
*/
t_fractol init_window(int win_height, int win_width, char *name)
{
	t_fractol fractol;

	fractol.window.height = win_height;
	fractol.window.width = win_width;
	fractol.max_iter = 50;
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr,
									fractol.window.width,
									fractol.window.height,
									name);

	return (fractol);
}



/*
** Display Mandelbrot Set
*/
t_fractol	display_mandlebrot(t_fractol frac)
{
	unsigned int w_iter;
	unsigned int h_iter;

	// printf("Display: %.32Lf\n", frac.view.x.max - frac.view.x.min);

	frac.mbrot.x_delta = (frac.view.x.max - frac.view.x.min) /
	(long double)frac.window.width;
	frac.mbrot.y_delta = (frac.view.y.max - frac.view.y.min) /
	(long double)frac.window.height;
	frac.mbrot.val_y = frac.view.y.min;


	h_iter = 0;
	while (h_iter < frac.window.height)
	{
		frac.mbrot.val_x = frac.view.x.min;
		w_iter = 0;
		while (w_iter < frac.window.width)
		{
			fractol_test(w_iter, h_iter, frac.mbrot.val_x, frac.mbrot.val_y, frac);
			frac.mbrot.val_x += frac.mbrot.x_delta;
			w_iter++;
		}
		frac.mbrot.val_y += frac.mbrot.y_delta;
		h_iter++;
	}

	return (frac);
}

t_fractol init_mandlebrot(t_fractol fractol)
{
	fractol.view.y.min = -1;
	fractol.view.y.max = 1;
	fractol.view.x.min = -2.5;
	fractol.view.x.max = 1;

	return (fractol);
}



int expose(void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol*)param;

	for(unsigned int x = 0; x < fractol->window.width; x++)
	{
		for(unsigned int y = 0; y < fractol->window.width; y++)
		{
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, x, y, 0xFF0000);
		}
	}

	return (0);
}

int mouse_pressed(int button, int x, int y, void *param)
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

int main(void)
{
	t_fractol fractol = init_window(800, 1400, "Fractol");
	fractol = init_mandlebrot(fractol);
	fractol = display_mandlebrot(fractol);

	mlx_mouse_hook(fractol.win_ptr, &mouse_pressed, (void *)&fractol);
	mlx_loop(fractol.mlx_ptr);
	return (0);
}
