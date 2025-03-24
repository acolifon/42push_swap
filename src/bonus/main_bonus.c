/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:24:48 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:23 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker_bonus.h"

int	main(int argc, char **argv)
{
	t_push	*push;

	if (argc == 1)
		free_and_close(NULL, EXIT_FAILURE);
	if (argc > 2)
	{
		push = init_push(argc, argv);
		is_digit(push->argv);
		init_stack(push);
		is_duplicate(push->stack_a);
		read_commands(push);
		verify_stack(push);
		free_and_close(push, EXIT_SUCCESS);
	}
	return (0);
}
