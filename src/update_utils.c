/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:21:41 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:54:57 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_index_median(t_stack_node *stack)
{
	int	i;
	int	mid;

	if (!stack)
		return ;
	i = 0;
	mid = (stack_size(stack) - 1) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

void	update_target(t_stack_node *stack_b, t_stack_node *stack_a)
{
	t_stack_node	*st_a;
	t_stack_node	*target;
	long			best_match;

	while (stack_b)
	{
		st_a = stack_a;
		best_match = LONG_MAX;
		while (st_a)
		{
			if (st_a->nbr > stack_b->nbr && st_a->nbr < best_match)
			{
				best_match = st_a->nbr;
				target = st_a;
			}
			st_a = st_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = smallest_nbr(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	update_target_b(t_stack_node *stack, t_stack_node *target)
{
	t_stack_node	*cur_b;
	t_stack_node	*target_node;
	long			best_match;

	while (target)
	{
		cur_b = stack;
		best_match = LONG_MIN;
		while (cur_b)
		{
			if (cur_b->nbr < target->nbr && cur_b->nbr > best_match)
			{
				best_match = cur_b->nbr;
				target_node = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_match == LONG_MIN)
			target->target_node = biggest_nbr(&stack);
		else
			target->target_node = target_node;
		target = target->next;
	}
}

void	update_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*cr_b;

	cr_b = stack_b;
	while (cr_b)
	{
		if (cr_b->above_median)
			cr_b->push_cost = cr_b->index;
		else if (!cr_b->above_median)
			cr_b->push_cost = stack_size(stack_b) - cr_b->index;
		if (cr_b->target_node->above_median)
			cr_b->push_cost += cr_b->target_node->index;
		else if (!cr_b->target_node->above_median)
			cr_b->push_cost += stack_size(stack_a) - cr_b->target_node->index;
		cr_b = cr_b->next;
	}
}

void	update_cheapest(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest_node;
	int				smallest_cost;

	if (!stack)
		return ;
	current = stack;
	smallest_cost = INT_MAX;
	while (current)
	{
		if (current->push_cost < smallest_cost)
		{
			smallest_cost = current->push_cost;
			cheapest_node = current;
		}
		current->cheapest = false;
		current = current->next;
	}
	cheapest_node->cheapest = true;
}
