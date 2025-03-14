/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:27:51 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/13 18:27:46 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node    **stack_a;
	t_stack_node    **stack_b;

	if (argc < 2)
		return (1);
	stack_a = ft_calloc(1, sizeof(t_stack_node *));
	stack_b = ft_calloc(1, sizeof(t_stack_node *));
	if (!stack_a)
		return (error_msg_int("ERROR: stack not allocate.\n"));
	if (argc == 2)
	{
		create_lst_split(stack_a, argv[1]);
	}
	else if (argc > 2)
		create_lst(stack_a, argv);
	if (is_duplicate(stack_a))
	{
		ft_printf("ERROR: numbers are duplicated.\n");
		exit_program_failure(stack_a, NULL);
	}
	if (is_inorder(stack_a))
		exit_program_failure(stack_a, NULL);
	clear_lst(stack_a);
	return (0);
}

//verificar int_min e int_max							ok
//verificar duplas										ok
//verificar se esta em ordem							ok
//criar função que limpa a lista e rentorna erro		ok

// 	fazer movimento
//		-push		(pa, pb)
//		-swap		(sa, sb, ss)
//		-rotate		(ra, rb. rr) -> nao e so chamar o ra e o rb no rr
//		-rev_rotate	(rra, rrb, rrr)

