/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:52:45 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:45:18 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	update_index_median(*stack_a);
	update_index_median(*stack_b);
	update_target(*stack_b, *stack_a);
	update_cost(*stack_a, *stack_b);
	update_cheapest(*stack_b);
}

void	update_stack_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	update_index_median(*stack_a);
	update_index_median(*stack_b);
	update_target_b(*stack_b, *stack_a);
	update_cost(*stack_b, *stack_a);
	update_cheapest(*stack_a);
}
