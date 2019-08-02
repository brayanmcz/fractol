/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 00:09:41 by brayancastr       #+#    #+#             */
/*   Updated: 2019/08/01 15:20:36 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/julia.h"
#include "../includes/parse.h"
#include "../includes/mandlebrot.h"

int run_julia(t_fractol frac){

    display_julia(frac);
    return (0);
}

t_fractol	display_julia(t_fractol frac)
{
// 	unsigned int w_iter;
// 	unsigned int h_iter;

// 	frac.mbrot.x_delta = (frac.view.x.max - frac.view.x.min) /
// 	(long double)frac.window.width;
// 	frac.mbrot.y_delta = (frac.view.y.max - frac.view.y.min) /
// 	(long double)frac.window.height;
// 	// frac.mbrot.val_y = frac.view.y.min;

// 	h_iter = 0;
// 	while (h_iter < frac.window.height)
// 	{
// 		frac.mbrot.val_x = frac.view.x.min;
// 		w_iter = 0;
// 		while (w_iter < frac.window.width)
// 		{
// 			fractol_test(w_iter, h_iter, frac.mbrot.val_x, frac.mbrot.val_y, frac);
// 			frac.mbrot.val_x += frac.mbrot.x_delta;
// 			w_iter++;
// 		}
// 		frac.mbrot.val_y += frac.mbrot.y_delta;
// 		h_iter++;
// 	}

	return (frac);
}