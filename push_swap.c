/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:14:03 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/29 18:53:24 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instructions(char *instructions)
{
	char	**instruction_list;

	if (instructions)
	{
		instruction_list = ft_strsplit(instructions, ' ');
		ft_putstrarr(instruction_list);
		ft_freestrarr(instruction_list);
	}
	free(instructions);
}

int			main(int argc, char **argv)
{
	t_stack	*stack;
	size_t	err_num;
	char	*instructions;

	if (argc == 1)
		return (exit_early(1));
	else if ((err_num = check_for_error(argv, argc)))
		return (exit_early(err_num));
	else if (!(stack = create_stack(argv, argc)))
		return (exit_midway(&stack));
	if (!(instructions = run_game(&stack, count_elements_in_stack(stack))))
		return (exit_midway(&stack));
	free_stack(&stack);
	print_instructions(instructions);
	return (0);
}
