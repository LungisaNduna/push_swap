/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:07:16 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/29 18:18:38 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_special_situation(t_stack *stack)
{
	size_t	return_value;

	if (in_order_top_to_bottom(stack))
		return_value = 0;
	else if (can_be_rotated_into_order(stack))
		return_value = 1;
	else if (count_elements_in_stack(stack) == 3)
		return_value = 2;
	else if (lowest_after_each_other(stack))
		return_value = 3;
	else
		return_value = 0;
	return (return_value);
}

static int		finished_running(t_stack *stack_a, int total_elements)
{
	if (!(in_order_top_to_bottom(stack_a)))
		return (0);
	if (count_elements_in_stack(stack_a) != total_elements)
		return (0);
	return (1);
}

char			*run_game(t_stack **stack, int num_of_elements)
{
	t_stack *stack_b;
	char	*instructions;
	char	*trash;
	char	*new_instr;
	size_t	situation;

	stack_b = NULL;
	instructions = ft_strdup("");
	while (finished_running(*stack, num_of_elements) == 0)
	{
		if ((situation = find_special_situation(*stack)))
			new_instr = handle_special_situation(stack, situation);
		else
			new_instr = keep_it_poppin(stack, &stack_b);
		trash = instructions;
		instructions = ft_strjoin(instructions, new_instr);
		ft_strdel(&trash);
		ft_strdel(&new_instr);
	}
	free_stack(&stack_b);
	return (instructions);
}
