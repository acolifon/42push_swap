/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:58:07 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 18:51:18 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"

void	push(t_stack_node **dest, t_stack_node **src, char letter)
{
	t_stack_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	tmp->prev = NULL;
	*dest = tmp;
	if (letter == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
