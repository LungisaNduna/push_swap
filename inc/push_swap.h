/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:29:29 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/31 13:14:41 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef	struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_ind
{
	int				a;
	int				b;
	int				c;
}					t_ind;

t_stack				*create_stack(char **input, int argc);
size_t				check_for_error(char **input, int argc);
void				free_stack(t_stack **stack);

void				push(t_stack **stack_from, t_stack **stack_to);
void				swap(t_stack **stack);
void				rot(t_stack **stack);
void				rev_rot(t_stack **stack);

char				*run_game(t_stack **stack, int num_of_elements);

int					count_elements_in_stack(t_stack *stack);
int					in_order_top_to_bottom(t_stack *stack);
int					can_be_rotated_into_order(t_stack *stack);
int					lowest_after_each_other(t_stack *stack);

t_stack				*get_lowest_element(t_stack *stack);
char				*get_to_top(t_stack **stack, t_stack *element);
char				*keep_it_poppin(t_stack **sa, t_stack **sb);
char				*handle_special_situation(t_stack **sa, size_t sitch);

int					exit_early(size_t err_num);
int					exit_midway(t_stack **stack);

void				print_stack(t_stack *stack);
void				print_stacks(t_stack *a, t_stack *b);

#endif
