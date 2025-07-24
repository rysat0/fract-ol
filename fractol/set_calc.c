/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:15:31 by rysato            #+#    #+#             */
/*   Updated: 2025/07/24 19:20:30 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scr_to_cpx(int pix_x, int pix_y, t_frac *fra, t_cpx *coord)
{
	double	plane_w;
	double	plane_h;

	plane_w = fra->view.max_real - fra->view.min_real;
	plane_h = fra->view.max_imag - fra->view.min_imag;
	coord->real = ((double)pix_x / (WIN_W - 1)) * plane_w + fra->view.min_real;
	coord->imag = fra->view.max_imag - ((double)pix_y / (WIN_H - 1)) * plane_h;
}

static int	iterate_set(t_cpx z, t_cpx c, const t_frac *fra)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (iter < fra->max_iter)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			break ;
		iter++;
	}
	return (iter);
}

int	pick_color(int ite, t_frac *fra)
{
	int	shade;

	if (ite == fra->max_iter)
		return (0x000000);
	shade = (ite * 5) % 256;
	if (fra->color_shift % 3 == 0)
		return (shade * 256 * 256);
	else if (fra->color_shift % 3 == 1)
		return (shade * 256);
	else
		return (shade);
}

static void	set_pixel(t_frac *fra, int pix_x, int pix_y, int ite)
{
	int		color;
	char	*dst;

	color = pick_color(ite, fra);
	dst = fra->img.data + (((pix_y * WIN_W) + pix_x) * 4);
	*(int *)dst = color;
}

void	draw_frac(t_frac *fra)
{
	int		pix_x;
	int		pix_y;
	int		ite;
	t_cpx	coord;

	pix_y = 0;
	while (pix_y < WIN_H)
	{
		pix_x = 0;
		while (pix_x < WIN_W)
		{
			scr_to_cpx(pix_x, pix_y, fra, &coord);
			if (fra->type == 1)
				ite = iterate_set((t_cpx){0, 0}, coord, fra);
			else if (fra->type == 2)
				ite = iterate_set(coord, (t_cpx){fra->ju_real, fra->ju_imag},
						fra);
			else
				ite = iterate_ship((t_cpx){0, 0}, coord, fra);
			set_pixel(fra, pix_x, pix_y, ite);
			pix_x++;
		}
		pix_y++;
	}
	mlx_put_image_to_window(fra->mlx, fra->win, fra->img.img_ptr, 0, 0);
}

// z[n+1] = (z[n])^2 + c
// c = a + bi
//(a + bi)^2 = a^2 - b ^2 + (2ab)i
//実部と虚部に分けて計算
//実部：a^2 - b^2 + cx(C実部)
//虚部：2 * a * b + cy(C虚部)

//マンデルブロ集合
// cの変化に対する発散収束を観測
// z[0]=0固定、座標の１点がcに対応している
//座標x,yで、c = x + yiに対応
//各座標をcにして計算

//ジュリア集合
// z[0]初期値に対する発散収束を観測
// cはコマンドライン引数で受取→固定
// argv[2] == real, argv[3] == imag で c = real + (imag)i
//座標の一点がz[0]に対応している
//座標x,yでz[0] = x + yi になる
//各座標をz[0]にして計算
