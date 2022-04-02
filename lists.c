/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:39:37 by maddi             #+#    #+#             */
/*   Updated: 2022/04/02 15:24:59 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_printlst(t_stack *tail)
{
    t_stack *current;

    current = tail;
    while (current->prev != tail)
    {
        printf("%d :: %d | pos = %d\n", current->lds, current->val, current->pos);
        current = current->prev;
    }
    printf("%d :: %d | pos = %d\n", current->lds, current->val, current->pos);
}

t_stack *ft_newlst(int value)
{
    t_stack *tmp;

    tmp = malloc(sizeof(t_stack));
    tmp->lds = 1;
    tmp->val = value;
    tmp->next = tmp;
    tmp->prev = tmp;
}

void   ft_addback(t_stack *tail, t_stack *newnode)
{
    t_stack *tmp;

    tmp = tail->next;
    newnode->next = tmp;
    newnode->prev = tail;
    tmp->prev = newnode;
    tail->next = newnode;
}

void    ft_addfront(t_stack **tail, t_stack *newnode)
{
    t_stack *head = (*tail)->next;
    
    head->prev = newnode;
    (*tail)->next = newnode;
    newnode->prev = (*tail);
    newnode->next = head;
}
