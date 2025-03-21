/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:30:48 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 19:05:14 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/push_swap_bonus.h"

void	read_commands(t_push *push_swap)
{
	char	*command;

	while (true)
	{
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_commands(push_swap, command);
		free(command);
	}
}

void	execute_commands(t_push *push_s, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(&push_s->stack_a, 'a');
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(&push_s->stack_a, 'b');
	else if (!ft_strncmp(command, "ss\n", 3))
		swap_a_b(&push_s->stack_a, &push_s->stack_b);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(&push_s->stack_a, &push_s->stack_b, 'a');
	else if (!ft_strncmp(command, "pb\n", 3))
		push(&push_s->stack_b, &push_s->stack_a, 'b');
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(&push_s->stack_a, 'a');
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(&push_s->stack_a, 'b');
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate_both(&push_s->stack_a, &push_s->stack_b);
	else if (!ft_strncmp(command, "rra\n", 4))
		rotate_rev(&push_s->stack_a, 'a');
	else if (!ft_strncmp(command, "rrb\n", 4))
        rotate_rev(&push_s->stack_b, 'b');
	else if (!ft_strncmp(command, "rrr\n", 4))
		rotate_rev_both(&push_s->stack_a, &push_s->stack_a);
	else
		free_moviments(push_s, command);
}

void	verify_stack(t_push *push_swap)
{
	int	length;

	length = stack_size(push_swap->stack_a);
	if ((is_inorder(push_swap->stack_a)) && \
		    (length == push_swap->len_a) && \
		(push_swap->stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
