/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 23:05:46 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/07 05:38:28 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		julia(t_data *data)
{
	double		tmp;

	data->x = -1;
	while (++data->x < HEIGHT)
	{
		data->y = -1;
		while (++data->y < WIDTH)
		{
			data->z_real = data->x / data->zoom + data->x_min;
			data->z_imag = data->y / data->zoom + data->y_min;
			data->iter_i = 0;
			while ((data->iter_i < data->iter_max) && (data->z_real *
						data->z_real + data->z_imag * data->z_imag < 4))
			{
				tmp = data->z_real;
				data->z_real = (data->z_real * data->z_real - data->z_imag *
					data->z_imag + data->c_real);
				data->z_imag = (2 * data->z_imag * tmp + data->c_imag);
				data->iter_i++;
			}
			set_pixel(data->x, data->y, data);
		}
	}
}
