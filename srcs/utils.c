/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 04:26:42 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/08 03:32:45 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	err_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	usage(void)
{
	ft_putstr("USAGE : ./fractol [number]\n\n");
	ft_putstr("example : ./fractol 1\n\n");
	ft_putstr("1. MANDELBROT press -> '1'\n");
	ft_putstr("2. JULIA press -> '2'\n");
	ft_putendl("3. BURNING_SHIP press -> '3'");
	exit(1);
}

void	init(t_data *data)
{
	data->c_real = 0.285;
	data->c_imag = 0.1;
	data->x_min = -2.1;
	data->x_max = 0.6;
	data->y_min = -1.2;
	data->y_max = 1.2;
	data->zoom = 200;
	data->iter_max = 50;
	data->bpp = 32;
}

void	set_string_win(t_data *data)
{
	char	*zoom1;
	char	*zoom2;

	zoom1 = "Zoom In   : + or Mouse Left Click or Scroll Ball Up";
	zoom2 = "Zoom Out  : - or Mouse Right Click or Scroll Ball Down";
	mlx_string_put(data->mlx, data->win, 20, 540, 0xff, "Reset : R");
	mlx_string_put(data->mlx, data->win, 20, 580, 0xff0000, "MOVE  :");
	mlx_string_put(data->mlx, data->win, 20, 600, 0xff, "Right : >");
	mlx_string_put(data->mlx, data->win, 20, 620, 0xff, "Left  : <");
	mlx_string_put(data->mlx, data->win, 20, 640, 0xff, "Up    : ^");
	mlx_string_put(data->mlx, data->win, 20, 660, 0xff, "Down  : v");
	mlx_string_put(data->mlx, data->win, 20, 700, 0xff0000, "ZOOM     : ");
	mlx_string_put(data->mlx, data->win, 20, 720, 0xff, zoom1);
	mlx_string_put(data->mlx, data->win, 20, 740, 0xff, zoom2);
}

int		put_string_in_screen(t_data *data)
{
	if (data->fract == 1)
	{
		mlx_string_put(data->mlx, data->win, 20, 520, 0xFF0000, "MANDELBROT");
		set_string_win(data);
	}
	else if (data->fract == 2)
	{
		mlx_string_put(data->mlx, data->win, 20, 520, 0xFF0000, "JULIA");
		set_string_win(data);
	}
	else if (data->fract == 3)
	{
		mlx_string_put(data->mlx, data->win, 20, 520, 0xFF0000, "BURNING_SHIP");
		set_string_win(data);
	}
	return (0);
}
