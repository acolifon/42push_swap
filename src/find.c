/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:11:18 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:42:56 by ancarol9         ###   ########.fr       */
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

