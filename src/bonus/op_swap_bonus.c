/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:05:09 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 19:01:23 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"

void	swap(t_stack_node **stack, char letter)
{
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->prev = *stack;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next->prev = tmp;
	if (letter == 'a')
		write(1, "sa\n", 3);
	else if (letter == 'b')
		write(1, "sb\n", 3);
}

void	swap_a_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	write(1, "ss\n", 3);
}
