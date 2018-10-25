/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btnsmash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:11:56 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/23 18:46:24 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*keep_it_poppin(t_stack **stack_a, t_stack **stack_b)
{
	static int	stack_a_in_order = 0;
	char		*trash;
	char		*instructions;

	if (!stack_a_in_order && in_order_top_to_bottom(*stack_a))
		stack_a_in_order = 1;
	if (!stack_a_in_order)
	{
		instructions = get_to_top(stack_a, get_lowest_element(*stack_a));
		push(stack_a, stack_b);
		trash = instructions;
		instructions = ft_strjoin(instructions, " pb");
		free(trash);
	}
	else
	{
		push(stack_b, stack_a);
		instructions = ft_strdup(" pa");
	}
	return (instructions);
}
