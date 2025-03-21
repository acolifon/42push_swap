/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:40 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 16:58:56 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_msg_int(const char *msg)
{
	if (!msg)
		msg = "Error\n";
	ft_printf("%s\n", msg);
	return (1);
}

void	exit_program_failure(t_stack_node **lst, char **nbrs, const char *msg)
{
	if (nbrs)
		ft_free(nbrs);
	if (msg)
		ft_printf("%s\n", msg);
	if (lst)
	{
		clear_lst(lst);
	}
	exit(EXIT_FAILURE);
}
