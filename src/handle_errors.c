/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_erros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:40 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/11 17:35:03 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_msg_int(const char *msg)
{
	if (!msg)
		msg = "ERROR: unknown error";
	ft_printf("%s.\n", msg);
	return (1);
}

void	exit_program_failure(t_stack_node **lst, char **nbrs)
{
	if (nbrs)
		ft_free(nbrs);
	if (lst)
	{
		clear_lst(lst);
		free(lst);					//MUDOU AQUI!!
	}
	exit(EXIT_FAILURE);	
}
