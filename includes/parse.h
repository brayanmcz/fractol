/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:21:26 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/31 18:53:35 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "./fractol.h"

void init_fractal(int i);
void parse_fractal(char *str);
void init_mandelbrot(void);
void init_julia(void);
t_fractol init_window(t_fractol fractol, int height, int width);

#endif 