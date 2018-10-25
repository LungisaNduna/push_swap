/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:38:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/04 14:06:26 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		because_of_norm(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strequ(op, "ra"))
		rot(stack_a);
	else if (ft_strequ(op, "rb"))
		rot(stack_b);
	else if (ft_strequ(op, "rr"))
	{
		rot(stack_a);
		rot(stack_b);
	}
	else if (ft_strequ(op, "rra"))
		rev_rot(stack_a);
	else if (ft_strequ(op, "rrb"))
		rev_rot(stack_a);
	else if (ft_strequ(op, "rrr"))
	{
		rev_rot(stack_a);
		rev_rot(stack_b);
	}
}

static void		execute_command(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!op)
		return ;
	if (ft_strequ(op, "sa"))
		swap(stack_a);
	else if (ft_strequ(op, "sb"))
		swap(stack_b);
	else if (ft_strequ(op, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strequ(op, "pa"))
		push(stack_b, stack_a);
	else if (ft_strequ(op, "pb"))
		push(stack_a, stack_b);
	else
		because_of_norm(op, stack_a, stack_b);
}

static void		check_order(t_stack **stack, int num_rooms, size_t error_found)
{
	t_stack	*temp;
	t_stack	*prev;

	prev = *stack;
	temp = prev->next;
	while (temp && error_found == 0)
	{
		if (prev->num > temp->num)
			error_found = 1;
		prev = prev->next;
		temp = temp->next;
	}
	if (error_found || count_elements_in_stack(*stack) != num_rooms)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	free_stack(stack);
}

static size_t	check_input(char *line)
{
	if (ft_strequ(line, "pa") || ft_strequ(line, "pb") ||
			ft_strequ(line, "sa") || ft_strequ(line, "sb") ||
			ft_strequ(line, "ss") || ft_strequ(line, "ra") ||
			ft_strequ(line, "rb") || ft_strequ(line, "rr") ||
			ft_strequ(line, "rra") || ft_strequ(line, "rrb") ||
			ft_strequ(line, "rrr"))
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	err_num;

	err_num = 0;
	if (argc == 1)
		return (exit_early(1));
	if ((err_num = check_for_error(argv, argc)))
		return (exit_early(err_num));
	if (!(stack_a = create_stack(argv, argc)))
		return (exit_early(4));
	stack_b = NULL;
	while (get_next_line(0, &line))
	{
		err_num = (err_num == 0) ? check_input(line) : err_num;
		execute_command(line, &stack_a, &stack_b);
		if (line)
			free(line);
		else
			line = NULL;
	}
	free_stack(&stack_b);
	check_order(&stack_a, argc - 1, err_num);
	return (0);
}
