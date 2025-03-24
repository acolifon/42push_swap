/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:42:34 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/24 15:23:59 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker_bonus.h"

int	stack_size(t_stack_node *lst)
{
	int				counter;
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

t_stack_node	*stack_last_node(t_stack_node *lst)
{
	t_stack_node	*ptr_lst;

	if (!lst)
		return (NULL);
	ptr_lst = lst;
	ft_printf("pass\n");
	while (ptr_lst->next != NULL)
	{
		ptr_lst = ptr_lst->next;
	}
	return (ptr_lst);
}

void	stackadd_back(t_stack_node *lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (!new)
		return ;
	if (lst == NULL)
	{
		lst = new;
		return ;
	}
	ft_printf("entrei\n");
	last = stack_last_node(lst);
	last->next = new;
	new->prev = last;
}

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
