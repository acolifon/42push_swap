/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:27:51 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 16:58:18 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**stack_a;

	if (argc < 2)
		return (1);
	stack_a = ft_calloc(1, sizeof(t_stack_node *));
	if (!stack_a)
		return (error_msg_int("Error\n"));
	if (argc == 2)
	{
		create_lst_split(stack_a, argv[1]);
	}
	else if (argc > 2)
		create_lst(stack_a, argv);
	if (is_duplicate(stack_a))
		exit_program_failure(stack_a, NULL, "Error");
	if (is_inorder(stack_a))
		exit_program_failure(stack_a, NULL, NULL);
	sort_stack(stack_a);
	clear_lst(stack_a);
	return (0);
}
