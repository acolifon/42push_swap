/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:00:18 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 15:19:37 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

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

//FUNCTIONS:

int				main(int argc, char **argv);

//clean_lst
void			ft_free(char **nbrs);
void			clear_lst(t_stack_node **lst);

//handle_errors
int				error_msg_int(const char *msg);
void			exit_program_failure(t_stack_node **lst, char **nbrs, \
					const char *msg);

//handle_lst
t_stack_node	*stack_lstlast(t_stack_node *lst);
t_stack_node	*create_node(long nb, int i);
void			stackadd_back(t_stack_node **lst, t_stack_node *new);
void			create_lst_split(t_stack_node **lst_node, char *nbrs);
void			create_lst(t_stack_node **lst, char **nbr);

//validate_nbrs
bool			is_duplicate(t_stack_node **lst);
bool			is_inorder(t_stack_node **lst);
bool			is_digit(char *nbr);

//operations
void			rotate_rev(t_stack_node **stack, char letter);
void			rotate_rev_both(t_stack_node **stack_a, t_stack_node **stack_b,
					t_stack_node *cheapest);
void			rotate(t_stack_node **stack, char letter);
void			rotate_both(t_stack_node **stack_a, t_stack_node **stack_b, \
					t_stack_node *cheapest);
void			push(t_stack_node **dest, t_stack_node **src, char letter);
void			swap(t_stack_node **stack, char letter);
void			swap_a_b(t_stack_node **stack_a, t_stack_node **stack_b);

//update_node
void			update_stack(t_stack_node **stack_a, t_stack_node **stack_b);
void			update_stack_a(t_stack_node **stack_a, t_stack_node **stack_b);

//update_utils
void			update_index_median(t_stack_node *stack);
void			update_target(t_stack_node *stack_b, t_stack_node *stack_a);
void			update_target_b(t_stack_node *stack, t_stack_node *target);
void			update_cost(t_stack_node *stack_a, t_stack_node *stack_b);
void			update_cheapest(t_stack_node *stack);

//find
int				stack_size(t_stack_node *lst);
t_stack_node	*biggest_nbr(t_stack_node **stack);
t_stack_node	*smallest_nbr(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);

//sort_stack
void			cheapest_on_top(t_stack_node **stack, t_stack_node *cheapest, \
					char letter);
void			push_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			move_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void			move(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_three(t_stack_node **stack, char letter);
void			sort_stack(t_stack_node **stack);

#endif