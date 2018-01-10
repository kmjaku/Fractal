/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:34:56 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/08 01:46:06 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static unsigned int		convert_rgb_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + ((b & 0xff)));
}

static void				coloring_fractal(t_data *data, int *tmp)
{
	if (data->fract == 1)
	{
		if (data->iter_i < data->iter_max)
			*tmp = convert_rgb_hex(0xDC, 0xDC, 0xDC) * data->iter_i;
		else if (data->iter_i == data->iter_max)
			*tmp = convert_rgb_hex(0, 0, 0);
	}
	else if (data->fract == 2)
	{
		if (data->iter_max > data->iter_i)
			*tmp = convert_rgb_hex(192, 192, 192) * data->iter_i;
		else if (data->iter_max == data->iter_i)
			*tmp = convert_rgb_hex(211, 211, 211);
	}
	else if (data->fract == 3)
	{
		if (data->iter_i < data->iter_max)
			*tmp = convert_rgb_hex(0xE6, 0xE6, 0xFA) * data->iter_i;
		else if (data->iter_i == data->iter_max)
			*tmp = convert_rgb_hex(0xFF, 0xFF, 0xE0);
	}
}

void					set_pixel(int x, int y, t_data *data)
{
	int				i;
	int				*tmp;

	tmp = (int*)&data->pixel;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (y * data->size_line) + (x * data->bpp / 8);
		tmp = (int*)&data->pixel[i];
		coloring_fractal(data, tmp);
	}
}

static void				chose(t_data *data)
{
	if (data->fract == 1)
		mandelbrot(data);
	else if (data->fract == 2)
		julia(data);
	else if (data->fract == 3)
		burning_ship(data);
}

void					draw(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	chose(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	put_string_in_screen(data);
	mlx_destroy_image(data->mlx, data->img);
}
