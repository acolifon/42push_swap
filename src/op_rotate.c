/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:39:11 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:48 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rotate(t_stack_node **stack, char letter)
{
    t_stack_node    *tmp;

    if (!stack || !*stack || !(*stack)->next) // Verifica se a pilha existe e tem mais de um nó
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    tmp->next = NULL;
    stackadd_back(stack, tmp);
    if (letter == 'a')
        write(1, "ra\n", 3);
    if (letter == 'b')
        write(1, "rb\n", 3);
}

void    rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, t_stack_node *cheapest)
{
    while (*stack_a != cheapest->target_node && *stack_b != cheapest)
    {
        rotate(stack_a, 'r');
        rotate(stack_b, 'r');
        write(1, "rr\n", 3);
    }
    update_index_median(*stack_a);
    update_index_median(*stack_b);
}