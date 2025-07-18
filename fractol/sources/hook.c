/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:54:26 by rysato            #+#    #+#             */
/*   Updated: 2025/07/18 21:32:45 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void handle_key(int keycode, t_frac *fra)
{
	if(keycode == ESCAPE)
		handle_close(fra);
	else if(keycode == KEY_C)
		fra->color_shift = (fra->color_shift + 1) % 3;
	else if(keycode == LEFT)
	{
		fra->view.min_real = fra->view.min_real - 0.1;
		fra->view.max_real = fra->view.max_real - 0.1;
	}
	else if(keycode == RIGHT)
	{
		fra->view.min_real = fra->view.min_real + 0.1;
		fra->view.max_real = fra->view.max_real + 0.1;
	}
	else if(keycode == UP)
	{
		fra->view.min_imag = fra->view.min_imag - 0.1;
		fra->view.max_imag = fra->view.max_imag - 0.1;
	}
	else if(keycode == DOWN)
	{
		fra->view.min_imag = fra->view.min_imag + 0.1;
		fra->view.max_imag = fra->view.max_imag + 0.1;
	}
	draw_frac(fra);
}

static void zoom_view(t_frac *fra, double factor, double pix_x, double pix_y)
{
	double	center_real;
	double	center_imag;
	double	width;
	double	height;

	width = fra->view.max_real - fra->view.min_real;
	height = fra->view.max_imag - fra->view.min_imag;
	center_real = fra->view.min_real + (pix_x / (WIN_W - 1)) * width;
	center_imag = fra->view.max_imag - (pix_y / (WIN_H - 1)) * height;
	width = width * factor;
	height = height * factor;
	fra->view.min_real = center_real - (width / 2.0);
	fra->view.max_real = center_real + (width / 2.0);
	fra->view.min_imag = center_imag - (height / 2.0);
	fra->view.max_imag = center_imag + (height / 2.0);
}

static void handle_mouse(int button, int x, int y, t_frac *fra)
{
	double factor;

	if(button == SCROLL_UP)
		factor = 0.8;
	else if(button == SCROLL_DOWN)
		factor = 1.2;
	else
		return ;
	zoom_view(fra, factor, (double)x, (double)y);
	draw_frac(fra);
}

void handle_close(t_frac *fra)
{
	if(fra->img.img_ptr)
		mlx_destroy_image(fra->mlx, fra->img.img_ptr);
	if(fra->win)
		mlx_destroy_window(fra->mlx, fra->win);
	mlx_destroy_display(fra->mlx);
	if(fra->mlx)
		free(fra->mlx);
}

void make_hook(t_frac *fra)
{
	mlx_key_hook(fra->win, handle_key, fra);
	mlx_mouse_hook(fra->win, handle_mouse, fra);
	mlx_hook(fra->win, 17, 0, handle_close, fra);
	return ;
}
