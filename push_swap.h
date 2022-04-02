/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:01:12 by maddi             #+#    #+#             */
/*   Updated: 2022/04/02 15:22:45 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
typedef struct s_stack {
    int val;
    int lds;
    int pos;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

void    ft_swap(t_stack **tail);
void    ft_rotate(t_stack **tail);
t_stack *ft_pop(t_stack **tail);
void    ft_push(t_stack *src, t_stack **dst);
void    ft_addfront(t_stack **tail, t_stack *newnode);
void    ft_printlst(t_stack *tail);
t_stack *ft_newlst(int value);
void   ft_addback(t_stack *tail, t_stack *newnode);






#endif