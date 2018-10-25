/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:02:16 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/06 13:57:25 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(int num)
{
	double x1;
	double x2;
	double dif;

	x1 = (num * 1.0) / 2;
	x2 = (x1 + (num / x1)) / 2;
	dif = (x1 - x2 < 0) ? -1 * (x1 - x2) : x1 - x2;
	while (dif >= 0.0000001)
	{
		x1 = x2;
		x2 = (x1 + (num / x1)) / 2;
		dif = (x1 - x2 < 0) ? -1 * (x1 - x2) : x1 - x2;
	}
	return (x2);
}