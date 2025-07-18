/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:24:41 by rysato            #+#    #+#             */
/*   Updated: 2025/07/18 23:09:14 by rysato           ###   ########.fr       */
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
	if (!(argc == 2 || argc == 4))
	{
		error_help();
		exit(1);
	}
	else if (argc == 2 && (!(ft_strncmp(argv[1], "mandel", 10) == 0)
				|| !(ft_strncmp(argv[1], "ship", 10) == 0)))
	{
		error_help();
		exit(1);
	}
	else if (argc == 4 && !(ft_strncmp(argv[1], "julia", 10) == 0))
	{
		if (!(ft_atod(argv[2]) >= INT_MAX || ft_atod(argv[3]) >= INT_MAX))
			return ;
		error_help();
		exit(1);
	}
	if(ft_atod(argv[1]) == 1)
		fra->type == 1;
	else if(ft_atod(argv[1]) == 2)
		fra->type == 2;
	else if(ft_atod(argv[1]) == 3)
		fra->type == 3;
}

void	initialize_fra(char **argv, t_frac *fra)
{
	if (fra->type == 2)
	{
		fra->ju_real = ft_atod(argv[2]); //実部
		fra->ju_imag = ft_atod(argv[3]); //虚部
	}
	fra->mlx = mlx_init();//x server
	if (fra->mlx == NULL)
		exit(1);
	fra->win = mlx_new_window(fra->mlx, WIN_W, WIN_H, "fract-ol");//window pointer
	if (fra->win == NULL)
		exit(1);
	fra->img.img_ptr = mlx_new_image(fra->mlx, WIN_W, WIN_H);//裏で一枚作成
	fra->img.data = mlx_get_data_addr(fra->img.img_ptr, &fra->img.bit_p_pix,
			&fra->img.byte_p_law, &fra->img.endian);
	fra->view.max_imag = 2.0;
	fra->view.max_real = 2.0;
	fra->view.min_imag = -2.0;
	fra->view.min_real = -2.0;
	fra->color_shift = 0;
}
