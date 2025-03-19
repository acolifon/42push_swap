/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:33:20 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:20:31 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sort_three(t_stack_node **stack, char letter)
{
    t_stack_node    *biggest;

    if (!*stack)
        return ;
    biggest = biggest_nbr(stack);
    if (*stack == biggest)
    {
        rotate(stack, letter);
    }
    else if ((*stack)->next == biggest)
        rotate_rev(stack, letter);
    if ((*stack)->nbr > (*stack)->next->nbr)
        swap(stack, letter);
}

void    push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
    if (stack_size(*stack_a) > 3 && !is_inorder(stack_a))
        push(stack_b, stack_a, 'b');
    if (stack_size(*stack_a) > 3 && !is_inorder(stack_a))
        push(stack_b, stack_a, 'b');
    while (stack_size(*stack_a) > 3 && !is_inorder(stack_a))
    {
        update_stack_a(stack_a, stack_b);
        move_to_b(stack_a, stack_b);
    }
    sort_three(stack_a, 'a');
}

void    cheapest_on_top(t_stack_node **stack, t_stack_node *cheapest, char letter)
{
    while (*stack != cheapest)
    {
        if (letter == 'a')
        {
            if (cheapest->above_median == true)
                rotate(stack, letter);
            else
                rotate_rev(stack, letter);
        }
        else if (letter == 'b')
        {
            if (cheapest->above_median == true)
                rotate(stack, letter);
            else
                rotate_rev(stack, letter);
            
        }   
    }
}

void    move(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *cheapest;

    cheapest = find_cheapest(*stack_b);
    if(cheapest->above_median && cheapest->target_node->above_median)
    rotate_both(stack_a, stack_b, cheapest);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
    rotate_rev_both(stack_a, stack_b, cheapest);
    cheapest_on_top(stack_b, cheapest, 'b');
    cheapest_on_top(stack_a, cheapest->target_node, 'a');
    push(stack_a, stack_b, 'a');
}

void    move_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *cheapest;
    
    cheapest = find_cheapest(*stack_a);
    if(cheapest->above_median && cheapest->target_node->above_median)
        rotate_both(stack_b, stack_a, cheapest);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
        rotate_rev_both(stack_b, stack_a, cheapest);
    cheapest_on_top(stack_a, cheapest, 'a');
    cheapest_on_top(stack_b, cheapest->target_node, 'b');
    push(stack_b, stack_a, 'b');
}

void    turk_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
    t_stack_node *smallest;

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
// tudo certo aqui
void    sort_stack(t_stack_node **stack)
{
    t_stack_node    **stack_b;

    stack_b = ft_calloc(1, sizeof(t_stack_node *));
    if (stack_size(*stack) < 4)
        sort_three(stack, 'a');
    else
        turk_sort(stack, stack_b);
}
