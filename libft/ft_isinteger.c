/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:17:56 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/03 12:21:23 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinteger(char *s)
{
	int	str_as_num;

	if (!ft_isnumber(s))
		return (0);
	if (ft_strlen(s) > 11)
		return (0);
	str_as_num = ft_atoi(s);
	if ((str_as_num >= 0 && s[0] == '-') || (str_as_num < 0 && s[0] != '-'))
		return (0);
	return (1);
}
