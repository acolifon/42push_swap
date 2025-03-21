/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:22:01 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 19:13:30 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../../libft/libft.h"



typedef struct s_stack_node
{
	long					nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

typedef struct	s_push
{
	int				argc;
	int				len_a;
	int				len_b;
	char			**argv;
	bool			is_split;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
}	t_push;

//FUNCTIONS

int				main(int argc, char **argv);

//operations
void			push(t_stack_node **dest, t_stack_node **src, char letter);
void			swap(t_stack_node **stack, char letter);
void			swap_a_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate(t_stack_node **stack, char letter);
void			rotate_rev(t_stack_node **stack, char letter);
void			rotate_both(t_stack_node **stack_a, t_stack_node **stack_b);
void			rotate_rev_both(t_stack_node **stack_a, t_stack_node **stack_b);

//FREES
void			free_and_close(t_push *push, short exit_code);
void			free_moviments(t_push *push, char *mv);

// NODE_UTILS
int				stack_size(t_stack_node *lst);
void			stackadd_back(t_stack_node *lst, t_stack_node *new);
void			update_index_median(t_stack_node *stack);
t_push			*init_push(int argc, char **argv);
void		    init_stack(t_push *push);
t_stack_node	*stack_last_node(t_stack_node *lst);

bool			is_inorder(t_stack_node *lst);
bool			is_digit(char **nbr);
bool			is_duplicate(t_stack_node *lst);

void			read_commands(t_push *push_swap);
void			verify_stack(t_push *push_swap);
void			execute_commands(t_push *push_s, char *command);



#endif