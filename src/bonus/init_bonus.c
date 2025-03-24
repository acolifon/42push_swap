/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:35:23 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:16 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker_bonus.h"

t_push	*init_push(int argc, char **argv)
{
	t_push	*push;

	push = ft_calloc(1, sizeof(t_push));
	if (!push)
		free_and_close(NULL, EXIT_FAILURE);
	if (argc == 2)
	{
		push->is_split = true;
		push->argv = (ft_split(argv[1], ' '));
	}
	else
	{
		push->argv = ++argv;
		push->is_split = false;
	}
	push->argc = argc;
	return (push);
}

t_stack_node	*create_node(long nb, int i)
{
	t_stack_node	*node;

	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
	{
		ft_printf("ERROR: Couldn't allocate memory.\n");
		return (NULL);
	}
	node->nbr = nb;
	node->index = i;
	return (node);
}

void	init_stack(t_push *push)
{
	int				i;
	long			nbr;
	t_stack_node	*new_node;

	i = 0;
	nbr = 0;
	while (push->argv[i])
	{
		nbr = ft_atol(push->argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free_and_close(push, EXIT_FAILURE);
			return ;
		}
		new_node = create_node(nbr, i);
		stackadd_back(push->stack_a, new_node);
		i++;
	}
	push->len_a = stack_size(push->stack_a);
	update_index_median(push->stack_a);
}
