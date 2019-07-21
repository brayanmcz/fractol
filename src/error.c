/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:14:09 by bcastro           #+#    #+#             */
/*   Updated: 2019/07/20 19:24:30 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void f_error(int n)
{
    switch(n)
    {
        printf("Errno: %d\n", n);
        case 0:
            ft_putstr("Usage: ./fractol <fractol_name>\n");
            break;  
        case 1:
            ft_putstr("Error: Not Supported, try 'mandlebrot', 'julia', or 'other'\n");
            break;
    }
    exit(1);
}