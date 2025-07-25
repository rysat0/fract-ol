/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:47:25 by rysato            #+#    #+#             */
/*   Updated: 2025/07/24 15:43:19 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_frac	fra;

	judge_fra(argc, argv, &fra);
	initialize_fra(argv, &fra);
	draw_frac(&fra);
	make_hook(&fra);
	mlx_loop(fra.mlx);
	return (0);
}

//コマンドライン引数でマンデルブロ集合/ジュリア集合を判別
//ジュリア集合の場合はz[0]の値をコマンドラインargv[2], argv[3]で指定
//エラーの場合は使い方を表示

//初期化
