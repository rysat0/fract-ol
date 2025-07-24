/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:24:41 by rysato            #+#    #+#             */
/*   Updated: 2025/07/24 18:44:28 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_help(void)
{
	write(2, "Invalid Input Detected\n", 24);
	write(2, "----------------------\n", 24);
	write(2, "When you want to calculate Mandelbrot Set,\n", 44);
	write(2, "Argument must be \"1\" and just it.\n", 35);
	write(2, "----------------------\n", 24);
	write(2, "When you want to calculate Julia Set,\n", 39);
	write(2, "First arg must be \"2\",\n", 24);
	write(2, "Second arg must be Real part number,\n", 38);
	write(2, "Third arg must be Number of imaginary part\n", 44);
	write(2, "----------------------\n", 24);
	write(2, "When you want to calculate Burning Ship Fractol,\n", 50);
	write(2, "Argument must be \"3\" and just it.\n", 35);
	write(2, "----------------------\n", 24);
}

void	judge_fra(int argc, char **argv, t_frac *fra)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandel", 6) == 0)
		fra->type = 1;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fra->type = 2;
		fra->ju_real = ft_atod(argv[2]);
		fra->ju_real = ft_atod(argv[3]);
	}
	else if (argc == 2 && ft_strncmp(argv[1], "ship", 4) == 0)
		fra->type = 3;
	else
	{
		error_help();
		exit(1);
	}
}

void	initialize_fra(char **argv, t_frac *fra)
{
	if (fra->type == 2)
	{
		fra->ju_real = ft_atod(argv[2]);
		fra->ju_imag = ft_atod(argv[3]);
	}
	fra->mlx = mlx_init();
	if (!fra->mlx)
		exit(1);
	fra->win = mlx_new_window(fra->mlx, WIN_W, WIN_H, "fract-ol");
	if (!fra->win)
		handle_close(fra);
	fra->img.img_ptr = mlx_new_image(fra->mlx, WIN_W, WIN_H);
	if (!fra->img.img_ptr)
		handle_close(fra);
	fra->img.data = mlx_get_data_addr(fra->img.img_ptr, &fra->img.bit_p_pix,
			&fra->img.byte_p_law, &fra->img.endian);
	fra->view.max_imag = 1.2;
	fra->view.max_real = 1.5;
	fra->view.min_imag = -1.2;
	fra->view.min_real = -1.5;
	fra->color_shift = 0;
	fra->max_iter = 50;
}
