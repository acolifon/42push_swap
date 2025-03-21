/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:48:15 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 14:50:28 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rev(t_stack_node **stack, char letter)
{
	t_stack_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = stack_lstlast(*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
	if (letter == 'a')
		write(1, "rra\n", 4);
	if (letter == 'b')
		write(1, "rrb\n", 4);
}

void	rotate_rev_both(t_stack_node **stack_a, t_stack_node **stack_b, \
						t_stack_node *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
	{
		rotate_rev(stack_a, 'r');
		rotate_rev(stack_b, 'r');
		write(1, "rrr\n", 4);
	}
	update_index_median(*stack_a);
	update_index_median(*stack_b);
}
