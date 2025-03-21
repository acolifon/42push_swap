/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:24:48 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 19:09:27 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"

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
		ft_printf("entrei\n");
		is_duplicate(push->stack_a);
		ft_printf("entrei\n");
		read_commands(push);
		ft_printf("entrei\n");
		verify_stack(push);
		ft_printf("entrei\n");
		free_and_close(push, EXIT_SUCCESS);
	}
	return (0);
}