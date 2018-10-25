/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:31:04 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/03 12:21:20 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_name(char *input_line)
{
	if (ft_strequ(input_line, "./checker") ||
			ft_strequ(input_line, "./push_swap"))
		return (1);
	return (0);
}

static t_stack	*create_stack_element(char *num_as_str)
{
	t_stack *stack_element;

	if (!(stack_element = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack_element->num = ft_atoi(num_as_str);
	stack_element->next = NULL;
	return (stack_element);
}

t_stack			*create_stack(char **input, int argc)
{
	static t_stack	*start = NULL;
	t_stack			*temp;
	size_t			index;

	input = (argc == 2) ? ft_strsplit(input[1], ' ') : input;
	index = (is_name(input[0])) ? 1 : 0;
	while (input[index])
	{
		if (!start)
		{
			if (!(start = create_stack_element(input[index++])))
				return (NULL);
			temp = start;
		}
		else
		{
			if (!(temp->next = create_stack_element(input[index++])))
				return (NULL);
			temp = temp->next;
		}
	}
	if (argc == 2)
		ft_freestrarr(input);
	return (start);
}

static size_t	check_for_duplicates(char **input)
{
	size_t	index;
	size_t	index_loop;

	index = (is_name(input[0])) ? 1 : 0;
	while (input[index + 1] != NULL)
	{
		index_loop = index + 1;
		while (input[index_loop] != NULL)
		{
			if (ft_strequ(input[index], input[index_loop]))
				return (3);
			index_loop++;
		}
		index++;
	}
	return (0);
}

size_t			check_for_error(char **input, int argc)
{
	size_t	index;
	size_t	error_num;

	error_num = 0;
	input = (argc == 2) ? ft_strsplit(input[1], ' ') : input;
	index = (is_name(input[0])) ? 1 : 0;
	while (input[index])
	{
		if (!ft_isinteger(input[index]))
			error_num = 2;
		index++;
	}
	if (error_num == 0)
		error_num = check_for_duplicates(input);
	if (argc == 2)
		ft_freestrarr(input);
	return (error_num);
}
