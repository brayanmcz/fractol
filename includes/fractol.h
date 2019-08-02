/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:40:02 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/01 15:14:53 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>
# include <math.h>
# include "stdio.h" //DELETE THIS

typedef struct	s_limit
{
	long double min;
	long double max;
}				t_limit;

typedef struct	s_window
{
	unsigned int	height;
	unsigned int	width;
}				t_window;

typedef struct	s_view
{
	t_limit x;
	t_limit y;
}				t_view;

typedef struct	s_mbrot
{
	long double	x_delta;
	long double y_delta;
	long double val_x[4];
	long double val_y[4];
}				t_mbrot;

typedef struct	s_fractol
{
	t_window	window;
	t_view		view;
	t_mbrot 	mbrot;
	int			max_iter;
	int			iter[4];
	long double	x[4];
	long double y[4];
	int			zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	char 		*name;
}				t_fractol;

#endif
