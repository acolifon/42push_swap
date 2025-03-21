/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:31:00 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 19:07:53 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"

bool	is_duplicate(t_stack_node *lst)
{
	long			nb;
	t_stack_node	*next_node;
	t_stack_node	*current_node;

	current_node = lst;
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

bool	is_digit(char **nbr)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!nbr)
		return (false);
	while (nbr[i])
	{
		if (nbr[i][j] == '-' || nbr[i][j] == '+')
			j++;
		if (!ft_isdigit(nbr[i][j]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_inorder(t_stack_node *lst)
{
	t_stack_node	*current_node;

	if (lst == NULL || lst->next == NULL)
		return (true);
	current_node = lst;
	while (current_node->next)
	{
		if (current_node->nbr > current_node->next->nbr)
			return (false);
		current_node = current_node->next;
	}
	return (true);
}


