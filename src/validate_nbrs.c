/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:46:54 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 16:27:09 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_duplicate(t_stack_node **lst)
{
	long			nb;
	t_stack_node	*next_node;
	t_stack_node	*current_node;

	current_node  = *lst;
	while (current_node)
	{
		nb = current_node->nbr;
		next_node = current_node->next;
		while (next_node)
		{
			if (nb == next_node->nbr)
				return (true);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (false);
}

bool	is_inorder(t_stack_node **lst)
{
	t_stack_node	*current_node;

	if (*lst == NULL || (*lst)->next == NULL)
		return(true);
	current_node = *lst;
	while (current_node->next)
	{
		if (current_node->nbr > current_node->next->nbr)
			return (false);
		current_node = current_node->next;
	}
	return (true);
}

bool	is_digit(char *nbr)
{
	if (!nbr)
		return (false);
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if(!ft_isdigit(*nbr))
			return (false);
		nbr++;
	}
	return( true);
}

