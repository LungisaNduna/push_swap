/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:52:34 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/22 18:17:24 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *string)
{
	size_t	index;

	if (!string || ft_strlen(string) == 0)
		return (0);
	index = 0;
	if (string[index] == '-' || string[index] == '+')
		index++;
	while (string[index])
	{
		if (ft_isdigit(string[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
