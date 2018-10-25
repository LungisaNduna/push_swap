/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:21:13 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/23 18:53:33 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*top_two_lowest_but_out_of_order(t_stack **stack_a)
{
	t_stack	*lowest;
	t_stack	*second;
	char	*instructions;
	char	*trash;

	lowest = get_lowest_element(*stack_a);
	second = *stack_a;
	while (second->next != NULL && second->next != lowest)
		second = second->next;
	instructions = get_to_top(stack_a, second);
	swap(stack_a);
	trash = instructions;
	instructions = ft_strjoin(instructions, " sa");
	free(trash);
	return (instructions);
}

char	*last_three_elements(t_stack **stack)
{
	swap(stack);
	return (ft_strdup(" sa"));
}

char	*handle_special_situation(t_stack **sa, size_t sitch)
{
	char	*instructions;
	char	*trash;
	char	*new_instr;

	instructions = ft_strdup("");
	new_instr = NULL;
	trash = instructions;
	if (sitch == 1)
		new_instr = get_to_top(sa, get_lowest_element(*sa));
	else if (sitch == 2)
		new_instr = last_three_elements(sa);
	else if (sitch == 3)
		new_instr = top_two_lowest_but_out_of_order(sa);
	instructions = ft_strjoin(instructions, new_instr);
	free(new_instr);
	free(trash);
	return (instructions);
}
