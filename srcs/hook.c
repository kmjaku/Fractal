/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:58:44 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/08 23:55:50 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		zoom_calc(t_data *data, int key, double x)
{
	if (key == RIGHT)
		data->x_min = data->zoom < x ? data->x_min - 0.1 : data->x_min - 0.0001;
	else if (key == LEFT)
		data->x_min = data->zoom < x ? data->x_min + 0.1 : data->x_min + 0.0001;
	else if (key == UP)
		data->y_min = data->zoom < x ? data->y_min + 0.1 : data->y_min + 0.0001;
	else if (key == DOWN)
		data->y_min = data->zoom < x ? data->y_min - 0.1 : data->y_min - 0.0001;
	return (0);
}

int		key_hook(int key, t_data *data)
{
	zoom_calc(data, key, 2000);
	if (key == ZOOM_IN)
		data->zoom *= 1.1;
	else if (key == ZOOM_OUT)
		data->zoom /= 1.1;
	else if (key == RESET)
		init(data);
	else if (key == ESC)
	{
		free(data);
		err_exit("Exit Program\n");
	}
	draw(data);
	return (0);
}

int		motion_mouse(int x, int y, t_data *data)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		data->c_real = (double)(x + 800 - WIDTH) / 1000;
		data->c_imag = (double)(y + 800 - HEIGHT) / 1000;
	}
	draw(data);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *data)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = (x / data->zoom) + data->x_min;
	tmp_y = (y / data->zoom) + data->y_min;
	if (button == MOUSE_IN && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data->zoom *= 1.45;
	else if (button == MOUSE_OUT && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data->zoom /= 1.45;
	else if (button == ZOOM_DCI && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data->zoom *= 1.45;
	else if (button == ZOOM_DCO && x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data->zoom /= 1.45;
	data->x_min = tmp_x - (x / data->zoom);
	data->y_min = tmp_y - (y / data->zoom);
	draw(data);
	return (0);
}
