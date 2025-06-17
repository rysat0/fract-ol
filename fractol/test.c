/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:28:25 by rysato            #+#    #+#             */
/*   Updated: 2025/06/15 16:40:20 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1656, 1024, "title here");
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	return(0);
}
