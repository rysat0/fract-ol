/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:53:34 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:53:34 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_a(int argc, char **argv, t_stack *stack)
{
	ssize_t	i;
	ssize_t	tmp;
	t_node	*target;

	i = 1;
	while (i < argc)
	{
		tmp = ft_atol(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (put_error_invalid(), node_free(stack), -1);
		target = make_new_node((int)tmp);
		if (target == NULL)
			return (put_error_invalid(), node_free(stack), -1);
		push_last(stack, target);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	if (malloc_initialize_stack(&stack_a, &stack_b) == -1)
		return (put_error_invalid(), 0);
	if (fill_stack_a(argc, argv, stack_a) == -1)
		return (stack_free(stack_a, stack_b), 0);
	if (make_rank(stack_a) == -1)
		return (node_free(stack_a), stack_free(stack_a, stack_b), 0);
	if (is_sorted(stack_a))
		return (node_free(stack_a), stack_free(stack_a, stack_b), 0);
	if (stack_a->size <= 5)
		under_five_pattern(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
	return (node_free(stack_a), stack_free(stack_a, stack_b), 0);
}

//コマンドライン引数でint配列受取(long)
//引数なしエラー処理(argc == 1)
//双方向循環リストとスタックをまとめる構造体を定義
// Aスタックのリストに先頭から数値を入れていく
//順位付け（座標圧縮）
//圧縮用の配列(malloc)にAリストコピー
//自力で一旦圧縮用配列を昇順でソート ここでの並び方は頭からランクになる
//ここで重複値,int範囲外チェックエラーならfreeしてエラー出す
//元の数値を渡したらランクを返す関数を作成(二分探索)
// Aスタックのリストに入っている数値をすべてランクに置換
//圧縮用の配列はfree
// swap動作関数をそれぞれ定義,出力と操作を同時に行うように
//ブール型でis_sorted関数を作成
//この段階（初期）でのAランクリストの要素数(サイズ)が5個以下なら特別パターンで最短ソート
//要素数が6以上ならチャンクソート開始
//チャンク幅決定
// Aの先頭を見て、決めたチャンク幅内の数値であればpbでBの先頭に送る
// Aの先頭を見て、チャンク範囲外であればraで一旦後回し
// pbしたあと、送った数値がチャンクの中央値以下であればrb実行でBを軽い降順にしておく
//最初のチャンク幅の数値をすべてBに送り終わったら次のチャンク幅を考える
// Aが空になるとき、Bは完璧ではないが軽い降順になっている
//ランクの最大値をBから探し、最短手順(rbかrrb)で先頭に持ってきて、paでAに送る
//次に大きい値をBから探し、最短手順で先頭に回し、Aに送る
//これをBが空になるまで行うと自動的に昇順でAが完成する

// stack free
// node free
// array free
