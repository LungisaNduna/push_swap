/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:50:16 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/29 18:21:26 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	ft_putendl("STACK");
	while (temp)
	{
		ft_putchar('\t');
		ft_putnbr(temp->num);
		ft_putchar('\n');
		temp = temp->next;
	}
}

static void	print_rest(t_stack *a, t_stack *b)
{
	while (a && b)
	{
		ft_putchar('\t');
		ft_putnbr(a->num);
		ft_putchar('\t');
		ft_putnbr(b->num);
		ft_putchar('\n');
		a = a->next;
		b = b->next;
	}
	ft_putchar('\t');
	ft_putchar('_');
	ft_putchar('\t');
	ft_putchar('_');
	ft_putchar('\n');
	ft_putchar('\t');
	ft_putchar('a');
	ft_putchar('\t');
	ft_putchar('b');
	ft_putchar('\n');
}

void		print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*bigger;
	t_stack	*smaller;
	char	tall_stack;

	bigger = (count_elements_in_stack(a) <= count_elements_in_stack(b)) ?
		a : b;
	tall_stack = (count_elements_in_stack(a) <= count_elements_in_stack(b)) ?
		'a' : 'b';
	smaller = (bigger == a) ? b : a;
	while (count_elements_in_stack(bigger) != count_elements_in_stack(smaller)
			&& bigger)
	{
		ft_putchar('\t');
		if (tall_stack == 'b')
			ft_putchar('\t');
		ft_putnbr(bigger->num);
		ft_putchar('\n');
		bigger = bigger->next;
	}
	if (tall_stack == 'a')
		print_rest(bigger, smaller);
	else
		print_rest(smaller, bigger);
}
