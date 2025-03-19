/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:52:45 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:10:34 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack_node *lst)
{
	int	counter;
	t_stack_node	*cur;

	counter = 0;
	cur = lst;
	while (cur)
	{
		counter++;
		cur = cur->next;
	}
	return (counter);
}

t_stack_node    *biggest_nbr(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *biggest_node;
	long			biggest_nbr;
	
    if (!*stack)
        return (NULL);
    current = *stack;
	biggest_nbr = LONG_MIN;
    biggest_node = NULL;
    while (current)
    {
        if (current->nbr > biggest_nbr)
		{
			biggest_nbr = current->nbr;
            biggest_node = current;
		}
        current = current->next;
    }
    return (biggest_node);
}

t_stack_node    *smallest_nbr(t_stack_node *stack)
{
    t_stack_node    *current;
    t_stack_node    *smallest_node;
	long			small_nb;

    if (!stack)
        return (NULL);
    current = stack;
	small_nb = LONG_MAX;
    while (current)
    {
        if (current->nbr < small_nb)
		{
			small_nb = current->nbr;
            smallest_node = current;
		}
        current = current->next;
    }
    return (smallest_node);
}

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

void   update_target(t_stack_node *stack_b, t_stack_node *stack_a)
{
    t_stack_node    *st_a;
    t_stack_node    *target;
    long            best_match;

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

void    update_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
    t_stack_node    *current_b;

    current_b = stack_b;
    while (current_b)
    {
        if(current_b->above_median)        //se NAO for acima da media
            current_b->push_cost = current_b->index;
        else if (!current_b->above_median)
            current_b->push_cost = stack_size(stack_b) - current_b->index;
        if (current_b->target_node->above_median)
            current_b->push_cost += current_b->target_node->index;
        else if (!current_b->target_node->above_median)
            current_b->push_cost += stack_size(stack_a) - current_b->target_node->index;
        current_b = current_b->next;
    }
}

t_stack_node    *find_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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

void    update_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
    update_index_median(*stack_a);
    update_index_median(*stack_b);
    update_target(*stack_b, *stack_a);
    update_cost(*stack_a, *stack_b);
    update_cheapest(*stack_b);
}

void    update_stack_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
    update_index_median(*stack_a);
    update_index_median(*stack_b);
    update_target_b(*stack_b, *stack_a);
	update_cost(*stack_b, *stack_a);
	update_cheapest(*stack_a);
}

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
