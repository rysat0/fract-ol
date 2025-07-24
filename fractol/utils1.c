/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:42:37 by rysato            #+#    #+#             */
/*   Updated: 2025/07/24 18:06:23 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	space_skip(int *i, const char *str)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	sum;
	double	decimal;
	double	divider;

	i = 0;
	sign = 1;
	sum = 0.0;
	decimal = 0.0;
	divider = 10.0;
	space_skip(&i, str);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		sum = sum * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal += (str[i++] - '0') / divider;
		divider *= 10.0;
	}
	return (sign * (sum + decimal));
}

int	iterate_ship(double za, double zb, double ca, double cb)
{
	int		ite;
	double	tmp;

	ite = 0;
	while (ite < MAX_ITER)
	{
		za = fabs(za);
		zb = fabs(zb);
		tmp = (za * za) - (zb * zb) + ca;
		zb = 2 * za * zb + cb;
		za = tmp;
		if ((za * za) + (zb * zb) > 4.0)
			break ;
		ite++;
	}
	return (ite);
}
