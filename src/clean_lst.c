/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:47:26 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:14 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	clear_lst(t_stack_node **lst)
{
	t_stack_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

