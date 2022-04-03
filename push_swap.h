/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:01:12 by maddi             #+#    #+#             */
/*   Updated: 2022/04/03 09:13:15 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <limits.h>


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
t_stack **ft_get_lds(t_stack *stack);
t_stack *ft_lds(t_stack *tail);
t_stack *ft_get_max_lds(t_stack *tail);
t_stack *ft_get_nearest_lower(t_stack *node);
long ft_atol(const char *str);
int ft_checkargs(int ac, char **av);
void    ft_rrotate(t_stack **tail);
int ft_send_down(t_stack *tail, t_stack *src, t_stack *dst);










#endif