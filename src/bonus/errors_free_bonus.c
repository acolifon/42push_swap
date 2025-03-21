/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:54:36 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 18:55:48 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"


void	ft_free_split(char **nbrs)
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

void	ft_free_lst(t_stack_node **lst)
{
	t_stack_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(lst);
}

void    free_and_close(t_push *push, short exit_code)
{
    if (push->argv && push->is_split)
        ft_free_split(push->argv);
    if (push->stack_a)
        ft_free_lst(&push->stack_a);
    if (push->stack_b)
        ft_free_lst(&push->stack_b);
    free(push);
    if (exit_code == EXIT_FAILURE)
        ft_printf("Error\n");
    exit(exit_code);
}

void    free_moviments(t_push *push, char *mv)
{
    free(mv);
    free_and_close(push, EXIT_FAILURE);
}