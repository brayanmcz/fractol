/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:34:51 by bcastro           #+#    #+#             */
/*   Updated: 2019/08/02 16:25:05 by bcastro          ###   ########.fr       */
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