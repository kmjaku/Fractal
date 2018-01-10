/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 04:24:00 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/08 03:31:33 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		usage();
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		err_exit("faile to allocate memory\n");
	if (ft_strcmp(argv[1], "1") == 0 || ft_strcmp(argv[1], "2") == 0 ||
			ft_strcmp(argv[1], "3") == 0)
		data->fract = ft_atoi(argv[1]);
	else
	{
		ft_putendl("\nyou chose a fractol who doesn't exist");
		ft_putendl("launch executable without argument to see usage");
		free(data);
		exit(1);
	}
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	init(data);
	draw(data);
	mlx_hook(data->win, 2, 3, key_hook, data);
	mlx_hook(data->win, 6, 7, motion_mouse, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
}
