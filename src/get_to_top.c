/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:34:18 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/03 11:38:29 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*get_lowest_element(t_stack *stack)
{
	t_stack	*stack_a;
	t_stack	*lowest;

	stack_a = stack->next;
	lowest = stack;
	while (stack_a)
	{
		if (stack_a->num < lowest->num)
			lowest = stack_a;
		stack_a = stack_a->next;
	}
	return (lowest);
}

static char	*rot_till_top(t_stack **stack, t_stack *elem, int sitch)
{
	char	*instr;
	char	*new_instr;
	char	*trash;

	instr = ft_strdup("");
	while (*stack != elem)
	{
		trash = instr;
		if (sitch == 1)
		{
			rot(stack);
			new_instr = ft_strdup(" ra");
		}
		else
		{
			rev_rot(stack);
			new_instr = ft_strdup(" rra");
		}
		instr = ft_strjoin(instr, new_instr);
		free(new_instr);
		free(trash);
	}
	return (instr);
}

char		*get_to_top(t_stack **stack, t_stack *element)
{
	char	*instructions;
	t_stack	*temp;
	int		index;
	int		total_elements;

	temp = *stack;
	index = 0;
	total_elements = count_elements_in_stack(*stack);
	while (temp && temp != element)
	{
		index++;
		temp = temp->next;
	}
	if (total_elements % 2 == 1 && index < total_elements / 2 + 1)
		instructions = rot_till_top(stack, element, 1);
	else if (index <= total_elements / 2)
		instructions = rot_till_top(stack, element, 1);
	else
		instructions = rot_till_top(stack, element, 2);
	return (instructions);
}
