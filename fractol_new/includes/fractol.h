/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:18:05 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/02 17:09:53 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>
# include <math.h>
# include "stdio.h" //DELETE BEFORE SUBMITTING
# include "./error.h"
# include "./fractol.h"
#define ZOOM prog.zoom
#define HT prog.win.height
#define WT prog.win.width
#define NAME prog.win.name
#define MLX prog.mlx_ptr
#define WIN prog.win_ptr
#define ITER prog.max_iter

/*
**  t_fractol
** Fractol types supported that can be entered by the user.
*/
typedef enum	e_fractol
{
	Mandelbrot,
	Julia,
	BurningShip
}				t_fractol;

/*
**  t_image
** Holds the necessary details for an mlx image
*/
typedef struct	s_image
{
	void		*img_ptr;
	int			*img_data;
	int			width_len;
	int			bits_per_pixel;
	int			endian;
}				t_image;

/*
**  s_limit
** Minimum and Maximum value for the x and y on the fractol plane being viewed.
*/
typedef struct	s_limit
{
	long double min;
	long double max;
}				t_limit;

/*
** t_view
** The X and Y of the view currently visible to the user.
*/
typedef struct	s_view
{
	t_limit x;
	t_limit y;
}				t_view;

/*
**  t_window
** The Height and Width of the window that will display the fractol.
*/
typedef struct	s_window
{
	unsigned int	height;
	unsigned int	width;
	char			*name;
}				t_window;

/*
** t_program
** Will hold the necessary structure to display the correct fractols.
*/
typedef struct	s_program
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	win;
	t_view		view;
	t_fractol	type;
	int			zoom;
	t_image		image;
	int			max_iter;

}				t_program;

#endif
