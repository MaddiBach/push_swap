/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:55:50 by maddi             #+#    #+#             */
/*   Updated: 2022/04/03 17:19:51 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_get_nearest_lower(t_stack *node)
{
    t_stack *tmp = node;
    
    if (node == NULL)
        return (NULL);
    node = node->next;
    while (node != tmp)
    {
        if (tmp->lds - 1 == node->lds)
            return (node);
        node = node->next;
    }
    return (NULL);
}

t_stack **ft_get_lds(t_stack *stack)
{
    int i;
    t_stack *max;
    t_stack **ldstab;
    //puts("NOT HERE\n");
    ft_lds(stack);
    max = ft_get_max_lds(stack);
    printf("max val = %d\n", max->val);
    ldstab = malloc(sizeof(t_stack *) * max->lds + 1);
    t_stack *tmp = max;
    ldstab[0] = max;
    
    
    i = 1;
    while (i < max->lds)
    {
        printf("max->lds = %d\n", max->lds);
        printf("i = %d\n", i);
        tmp = ft_get_nearest_lower(tmp);
        ldstab[i] = tmp;
        i++;
    }
    ldstab[i] = NULL;
    return (ldstab);
}

t_stack *ft_get_max_lds(t_stack *tail)
{
    t_stack *current = tail->prev;
    t_stack *max = tail;
    
    while (current != tail)
    {
        if (current->lds > max->lds)
            max = current;
        current = current->prev;
    }
    return (max);
}

t_stack *ft_lds(t_stack *tail)
{
    t_stack *i;
    t_stack *j;
    t_stack *stop;
    
    stop = tail;
    i = tail->prev;
    while (i != stop)
    {
        j = i->prev;
        while (j != i)
        {
            if (i->val > j->val && i->lds < j->lds + 1)
                i->lds = j->lds + 1;
            j = j->prev;
        }
        i = i->prev;
    }
    return (tail);
}
