/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:33:20 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 15:31:02 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **stack, char letter)
{
	t_stack_node	*biggest;

	if (!*stack)
		return ;
	biggest = biggest_nbr(stack);
	if (*stack == biggest)
		rotate(stack, letter);
	else if ((*stack)->next == biggest)
		rotate_rev(stack, letter);
	if ((*stack)->nbr > (*stack)->next->nbr)
		swap(stack, letter);
}

void	turk_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*smallest;

	push_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		update_stack(stack_a, stack_b);
		move(stack_a, stack_b);
	}
	update_index_median(*stack_a);
	smallest = smallest_nbr(*stack_a);
	if (smallest->above_median)
	{
		while (*stack_a != smallest)
			rotate(stack_a, 'a');
	}
	if (!smallest->above_median)
	{
		while (*stack_a != smallest)
			rotate_rev(stack_a, 'a');
	}
}

void	sort_stack(t_stack_node **stack)
{
	t_stack_node	**stack_b;

	stack_b = ft_calloc(1, sizeof(t_stack_node *));
	if (stack_size(*stack) < 4)
		sort_three(stack, 'a');
	else
		turk_sort(stack, stack_b);
	free(stack_b);
}
