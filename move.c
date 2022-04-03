/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:04:52 by maddi             #+#    #+#             */
/*   Updated: 2022/04/03 09:20:23 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_send_down(t_stack *tail, t_stack *src, t_stack *dst)
{

    int i = 0;
    printf("hello\n");
    while (src->val != tail->val)
    {
        printf("rr\n");
       // printf("src->val = %d || tail->val = ")
        ft_rrotate(&tail);
        i++;
    }
    ft_push(src, &dst);
}


int ft_send_up(t_stack *tail, t_stack *src, t_stack *dst)
{
    if (src == NULL || tail == NULL || dst == NULL)
        return (0);
    while (src != tail)
        ft_rotate(&tail);
    ft_push(src, &dst);
}