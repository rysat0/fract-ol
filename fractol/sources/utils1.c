/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:42:37 by rysato            #+#    #+#             */
/*   Updated: 2025/06/15 15:18:49 by rysato           ###   ########.fr       */
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

const void	space_skip(int *i, const char *str)
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

	sign = 1;
	i = 0;
	decimal = 0.0;
	sum = INT_MAX;
	divider = 0;
	space_skip(&i, str);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		sum = (sum * 10) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal = (str[i++] - '0') / divider;
		divider = divider * 10.0;
	}
	return (sign * (sum + decimal));
}
