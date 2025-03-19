/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:58:07 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:15 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push(t_stack_node **dest, t_stack_node **src, char letter)
{
    t_stack_node    *tmp;

    if (!src || !*src)              // se a lista ou o prrmeiro no exitem
        return ;                    //nap faz nada
    tmp = *src;                     //o primeiro no->src fica salvo na temp
    *src = (*src)->next;            //colca o proxmo no->src como primeiro
    if(*src)                        //se nao for null
        (*src)->prev = NULL;        //se existir, informa que nao tem nos antes
    tmp->next = *dest;              //adiciona como next a lista destino
    if(*dest)                       //se ela existir...
        (*dest)->prev = tmp;        //adiciona como no anterior o novo no
    tmp->prev = NULL;
    *dest = tmp;
    if (letter == 'a')
        write(1, "pa\n", 3);
    else    
        write(1, "pb\n", 3);
}
