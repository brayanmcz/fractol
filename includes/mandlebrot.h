/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:47:38 by brayancastr       #+#    #+#             */
/*   Updated: 2019/07/21 21:58:38 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "./fractol.h"

int createRGB(int r, int g, int b);
int calc_color(int iter, int max_iter);
void fractol_test(int Px, int Py, long double x0, long double y0, t_fractol fractol);
t_fractol	display_mandlebrot(t_fractol frac);
int mouse_pressed_zoom(int button, int x, int y, void *param);

#endif