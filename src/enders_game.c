/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enders_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:53:47 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/03 11:48:00 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *trash;
	t_stack *temp;

	if (stack)
	{
		temp = *stack;
		while (temp)
		{
			trash = temp;
			temp = temp->next;
			free(trash);
		}
	}
	*stack = NULL;
}

int		exit_early(size_t err_num)
{
	if (err_num == 1)
		ft_putendl("Error : No input to sort");
	else if (err_num == 2)
		ft_putendl("Error : Non-integer value in input");
	else if (err_num == 3)
		ft_putendl("Error : Found duplicates in input");
	else
		ft_putendl("Error");
	return (0);
}

int		exit_midway(t_stack **stack)
{
	free_stack(stack);
	return (exit_early(4));
}
