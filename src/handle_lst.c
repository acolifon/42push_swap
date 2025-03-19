/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:49:33 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 18:28:10 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*stack_lstlast(t_stack_node *lst)
{
	t_stack_node	*ptr_lst;

	if (!lst)
		return (NULL);
	ptr_lst = lst;
	while (ptr_lst->next != NULL)
	{
		ptr_lst = ptr_lst->next;
	}
	return (ptr_lst);
}

void	stackadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;
	
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = stack_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

t_stack_node    *create_node(long nb, int i)
{
	t_stack_node    *node;

	node = ft_calloc(1, sizeof(t_stack_node));
	if (!node)
	{
		ft_printf("ERROR: Couldn't allocate memory.\n");
		return(NULL);
	}
	node->nbr = nb;
	node->index = i;
	return(node);
}

void    create_lst_split(t_stack_node **lst_node, char *nbrs)
{
	int 			i;
	long			nb;
	char			**nbr_arr;
	t_stack_node	*node;

	i = 0;
	nbr_arr = ft_split(nbrs, ' ');
	while (nbr_arr[i])
	{
		if (!is_digit(nbr_arr[i]))
		{
			ft_printf("Error\n");
			exit_program_failure(lst_node, nbr_arr);
		}
		nb = ft_atol(nbr_arr[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			ft_printf("Error\n");
			exit_program_failure(lst_node, nbr_arr);
		}
		node = create_node(nb, i); 
		if(!node)
			exit_program_failure(lst_node, nbr_arr);
		stackadd_back(lst_node, node);
		i++;
	}
	ft_free(nbr_arr);
}

void	create_lst(t_stack_node **lst, char **nbr)
{
	int 			i;
	long			nb;
	t_stack_node	*node;

	i = 1;
	while (nbr[i])
	{
		if (!is_digit(nbr[i]))
		{
			ft_printf("Error\n");
			exit_program_failure(lst, NULL);
		}
		nb = ft_atol(nbr[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			ft_printf("Error\n");
			exit_program_failure(lst, NULL);
		}
		node = create_node(nb, i);
		if(!node)
			exit_program_failure(lst, NULL);
		stackadd_back(lst, node);
		i++;
	}
}