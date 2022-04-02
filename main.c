/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:00:48 by maddi             #+#    #+#             */
/*   Updated: 2022/04/02 17:52:00 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>



int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	//if (!ft_strncmp(str, "-2147483648", ft_strlen((char *)str)))
	//	return (-2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
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

t_stack *ft_get_max_lds(t_stack *tail)
{
    t_stack *stop = tail->next;
    t_stack *max = tail;
    
    while (tail != stop)
    {
        if (tail->lds > max->lds)
            max = tail;
        tail = tail->prev;
    }
    return (max);
}

t_stack *ft_get_nearest_lower(t_stack *node)
{
    t_stack *tmp = node;
    
    node = node->next;
    while (node != tmp)
    {
        if (tmp->val > node->val)
            return (node);
        node = node->next;
    }
    return (node);
}


int main(int ac, char **av)
{
    int i = 2;
    
    t_stack *stack = ft_newlst(ft_atoi(av[1]));
    stack->pos = 1;
    while (av[i])
    {
        t_stack *newnode = ft_newlst(ft_atoi(av[i]));
        newnode->pos = i;
        ft_addfront(&stack, newnode );       
        i++;
    }
    ft_printlst(stack);
    ft_lds(stack);
    puts("---------------");
    ft_printlst(stack);
    t_stack *max = ft_get_max_lds(stack);
    printf("lds = %d val = %d\n", max->lds, max->val);
    t_stack **lds = malloc(sizeof(t_stack *) * max->lds);
    i = 0;
    t_stack *tmp = ft_get_nearest_lower(max);
    printf("near low = %d\n",  tmp->val); 
    tmp = ft_get_nearest_lower(tmp);
    printf("near low = %d\n",  tmp->val);
    tmp = ft_get_nearest_lower(tmp);
    printf("near low = %d\n",  tmp->val);
}
/*
int main()
{
    t_stack *tail = ft_newlst(4);
    ft_addback(tail, ft_newlst(5));
    ft_addback(tail, ft_newlst(6));
    ft_addback(tail, ft_newlst(7));
    ft_addback(tail, ft_newlst(8));
    puts("------OG------");
    ft_printlst(tail);
    puts("------SWAP------");
    ft_swap(&tail);
    ft_printlst(tail);
    puts("------ROT------");
    ft_rotate(&tail);
    ft_printlst(tail);
    puts("----POPPED------");
    t_stack *pop = ft_pop(&tail);
    ft_printlst(tail);
    printf("popped = %d\n", pop->val);
    puts("-----PUSH----");
    t_stack *stack2 = ft_newlst(0);
    ft_push(tail, &stack2);
    ft_printlst(stack2); 
}
*/