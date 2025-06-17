/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:47:23 by rysato            #+#    #+#             */
/*   Updated: 2025/06/14 11:47:24 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 1656
# define WIN_H 1024

typedef struct s_cpx
{
	double	real;
	double	imag;
}			t_cpx;

typedef struct s_view
{
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
}			t_view;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bit_p_pix;
	int		byte_p_law;
	int		endian;
}			t_img;

typedef struct s_frac
{
	void	*mlx;
	void	*win;
	int		type;
	double	ju_real;
	double	ju_imag;
	t_img	img;
	t_view	view;

}			t_frac;

// type == 1  mandel
// type == 2  julia

#endif FRACTOL_H
