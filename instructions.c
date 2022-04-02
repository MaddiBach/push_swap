/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:12:57 by maddi             #+#    #+#             */
/*   Updated: 2022/04/02 11:44:26 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_stack **tail)
{
    t_stack *head;
    t_stack *tmp;    
    
    if ((*tail)->next == (*tail) || (*tail) == NULL)
        return ;
    tmp = (*tail)->prev;
    head = (*tail)->next;
    head->prev = tmp;
    tmp->next = head;
    (*tail)->prev = tmp->prev;
    tmp->prev = (*tail);
    (*tail)->next = tmp;
    (*tail) = tmp;
}

void    ft_rotate(t_stack **tail)
{
    if ((*tail) == NULL)
        return ;
    (*tail) = (*tail)->prev;
}

void    ft_push(t_stack *src, t_stack **dst)
{
    t_stack *head;
    t_stack *pop;
    
    if ((*dst) == NULL || &src == NULL)
        return;
    
    pop = ft_pop(&src);
    ft_addfront(dst, pop);
}

t_stack *ft_pop(t_stack **tail)
{
    t_stack *tmp;
    t_stack *head;
    t_stack *pop;

    if ((*tail) == NULL)
        return (NULL);
    pop = (*tail);
    tmp = (*tail)->prev;
    head = (*tail)->next;
    head->prev = tmp;
    tmp->next = head;
    (*tail) = tmp;
    pop->next = NULL;
    pop->prev = NULL;
    return (pop);
}
