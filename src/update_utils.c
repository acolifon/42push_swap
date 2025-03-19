/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:21:41 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 17:42:24 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    update_index_median(t_stack_node *stack)
{
	int             i;
	int             mid;

	if(!stack)
		return ;
	i = 0;
	mid = (stack_size(stack) - 1) / 2;
	while (stack)
	{
		stack->index = i;
		if(i <= mid)
			stack->above_median = true;
		else
			stack->above_median = false;
		i++;
		stack = stack->next;
	}
}

//update target_b encontra o menor maior
void   update_target_b(t_stack_node *stack, t_stack_node *target)
{
	t_stack_node    *cur_b;
	t_stack_node    *target_node;
	long            best_match;

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

//update_target_a encontra o maior menor
void   update_target(t_stack_node *target, t_stack_node *stack)
{
	t_stack_node    *cur_a;
	t_stack_node    *target_node;
	long            best_match;

	while (target)
	{
		cur_a = stack;
		best_match = LONG_MAX;
		while (cur_a)
		{
			if (cur_a->nbr > target->nbr && cur_a->nbr < best_match)
			{
				best_match = cur_a->nbr;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			target->target_node = smallest_nbr(stack);
		else
			target->target_node = target_node;
		target = target->next;
	}
}

void    update_cost(t_stack_node *stack, t_stack_node *target)
{
	t_stack_node    *cur;

	cur = stack;
	while (cur)
	{
		if(cur->above_median)
			cur->push_cost = cur->index;
		else if (!cur->above_median)
			cur->push_cost = stack_size(stack) - cur->index;
		if (cur->target_node->above_median)
			cur->push_cost += cur->target_node->index;
		else if (!cur->target_node->above_median)
			cur->push_cost += stack_size(target) - cur->target_node->index;
		cur = cur->next;
	}
}

void   update_cheapest(t_stack_node *stack)
{
	t_stack_node    *current;
	t_stack_node    *cheapest_node;
	int             smallest_cost;

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