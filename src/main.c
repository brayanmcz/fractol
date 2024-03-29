/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:34:51 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/21 22:15:40 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/parse.h"
#include "../includes/error.h"

int main(int argc, char **argv)
{  
    if (argc == 2){
        parse_fractal(argv[1]);
    }
    else
        f_error(0);
}