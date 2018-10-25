/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:02:08 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/29 18:15:41 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_elements_in_stack(t_stack *stack)
{
	t_stack	*temp;
	int		counter;

	counter = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

int		in_order_top_to_bottom(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*next;

	temp = stack;
	while (temp->next)
	{
		next = temp->next;
		if (temp->num > next->num)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int		can_be_rotated_into_order(t_stack *stack)
{
	t_stack	*temp_next;

	if (!(in_order_top_to_bottom(get_lowest_element(stack))))
		return (0);
	if (get_lowest_element(stack) != stack)
	{
		while (stack->next != get_lowest_element(stack))
		{
			temp_next = stack->next;
			if (stack->num > temp_next->num)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

int		lowest_after_each_other(t_stack *stack)
{
	t_stack *lowest;
	t_stack *checker;
	t_stack *temp;

	lowest = get_lowest_element(stack);
	checker = stack;
	while (checker->next != NULL && checker->next != lowest)
		checker = checker->next;
	temp = stack;
	while (temp != NULL)
	{
		if (checker->num > temp->num && temp != lowest && temp != checker)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*only_this_one_out_of_order(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp_next;
	t_stack	*out_of_place;

	temp = stack;
	out_of_place = NULL;
	while (temp->next != NULL)
	{
		temp_next = stack->next;
		if (temp_next->num < temp->num)
		{
			if ((in_order_top_to_bottom(temp_next)))
				return (temp_next);
		}
		temp = temp->next;
	}
	return (out_of_place);
}
