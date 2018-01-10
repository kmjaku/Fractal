/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 04:02:03 by kmjaku            #+#    #+#             */
/*   Updated: 2017/04/08 03:29:47 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../mlx/minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH 800
# define HEIGHT 800
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define RESET 15
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define MANDELBROT 84
# define JULIA 83
# define MOUSE_IN 5
# define MOUSE_OUT 4
# define ZOOM_DCI 1
# define ZOOM_DCO 2
# define ESC 53

typedef struct s_data
{
	int			fract;
	char		*pixel;
	int			endian;
	int			bpp;
	int			size_line;
	double		iter_i;
	double		iter_max;
	double		zoom;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		c_real;
	double		c_imag;
	double		z_real;
	double		z_imag;
	int			x;
	int			y;
	void		*img;
	void		*win;
	void		*mlx;
}				t_data;

int				put_string_in_screen(t_data *data);
void			usage(void);
void			draw(t_data *data);
void			init(t_data *data);
void			burning_ship(t_data *data);
void			julia(t_data *data);
void			mandelbrot(t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				motion_mouse(int x, int y, t_data *data);
int				key_hook(int key, t_data *data);
void			set_pixel(int x, int y, t_data *data);
void			err_exit(char *str);

#endif
