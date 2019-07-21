/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:13:29 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/20 20:37:10 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void init_fractal(int i)
{

}

void parse_fractal(char *str)
{
    if (ft_strcmp(str, "mandelbrot") == 0)
        init_fractal(1);
    else if (ft_strcmp(str, "julia") == 0)
        init_fractal(2);
    else if (ft_strcmp(str, "other") == 0)
        init_fractal(3);
    else 
        f_error(1);
}