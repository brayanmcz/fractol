/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brayancastro <brayancastro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:34:51 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/04 18:15:19 by brayancastr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/parse.h"

int main(int argc, char **argv)
{  
    t_program prog;
    prog.zoom = 1;
    if (argc == 2){
        parse_fractal(argv[1], prog);
    }

    return (0);
}