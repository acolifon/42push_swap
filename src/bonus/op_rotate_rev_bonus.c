/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_rev_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:48:15 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:59 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker_bonus.h"

void	rotate_rev(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = stack_last_node(*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	rotate_rev_both(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate_rev(stack_a);
	rotate_rev(stack_b);
	update_index_median(*stack_a);
	update_index_median(*stack_b);
}
