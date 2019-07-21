/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:34:51 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/20 20:47:55 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
    
    if (argc == 2){
        parse_fractol(argv[1]);
    }
    else
        f_error(0);
}