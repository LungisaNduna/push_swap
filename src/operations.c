/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:05:47 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/04 13:55:01 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*immigrant;

	immigrant = *stack_from;
	if (immigrant)
	{
		*stack_from = immigrant->next;
		immigrant->next = *stack_to;
		*stack_to = immigrant;
	}
}

void	swap(t_stack **stack)
{
	t_stack	*first_element;
	t_stack *second_element;

	first_element = *stack;
	if (first_element != NULL && first_element->next != NULL)
	{
		second_element = first_element->next;
		first_element->next = second_element->next;
		second_element->next = first_element;
		*stack = second_element;
	}
}

void	rot(t_stack **stack)
{
	t_stack	*temp_stack;
	t_stack	*mover;

	mover = *stack;
	if (mover != NULL && mover->next != NULL)
	{
		temp_stack = mover->next;
		*stack = mover->next;
		while (temp_stack->next != NULL)
			temp_stack = temp_stack->next;
		temp_stack->next = mover;
		mover->next = NULL;
	}
}

void	rev_rot(t_stack **stack)
{
	t_stack *temp_stack;
	t_stack *mover;

	temp_stack = *stack;
	if (temp_stack != NULL && temp_stack->next != NULL)
	{
		while (temp_stack->next != NULL)
			temp_stack = temp_stack->next;
		mover = temp_stack;
		temp_stack = *stack;
		while (temp_stack->next != mover)
			temp_stack = temp_stack->next;
		temp_stack->next = NULL;
		mover->next = *stack;
		*stack = mover;
	}
}
