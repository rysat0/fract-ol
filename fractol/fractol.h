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

# define MAX_ITER 50

# define WIN_W 1656
# define WIN_H 1024

# define ESCAPE 65307
# define KEY_C 99
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364

# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
	int		color_shift;
	int		max_iter;
	double	ju_real;
	double	ju_imag;
	t_img	img;
	t_view	view;

}			t_frac;

// type == 1  mandel
// type == 2  julia
// type == 3  burning ship

void		judge_fra(int argc, char **argv, t_frac *fra);
void		initialize_fra(char **argv, t_frac *fra);
void		draw_frac(t_frac *fra);
void		make_hook(t_frac *fra);
int			handle_close(t_frac *fra);
double		ft_atod(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			pick_color(int ite, t_frac *fra);
int			iterate_ship(t_cpx z, t_cpx c, const t_frac *fra);

#endif
