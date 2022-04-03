/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:00:48 by maddi             #+#    #+#             */
/*   Updated: 2022/04/03 17:20:37 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



long	ft_atol(const char *str)
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
	if (!ft_strncmp(str, "-2147483648", ft_strlen((char *)str)))
		return (-2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

t_stack *ft_fillstack(int ac, char **av)
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
    return (stack);
}


/*
int main(int ac, char **av)
{
    ft_checkargs(ac, av);
}*/

/*
int main(int ac, char **av)
{
    if (ac == 2)
        av = ft_split(av[1], ' ');
    if (!ft_checktype(av))
        return (1);
    if (!ft_checkdups(av))
        printf("Error\n");
    else 
        printf("Clean");
}
/
/*
int main(int ac,  char **av)
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
}
*/

int main(int ac, char **av)
{
    if (!ft_checkargs(ac, av))
        return (0);
    t_stack *stack;
    stack = ft_fillstack(ac, av);
    puts("-------OG---------");
    ft_printlst(stack);  

    puts("-------LDS SET---------");
    t_stack **ldstab = ft_get_lds(stack);
    ft_printlst(stack);
    puts("-----lds tab -----");
    for (int j = 0; ldstab[j]; j++)
        printf("val = %d\n", ldstab[j]->val);
    

    
//    t_stack **lds = ft_get_lds(stack);
//    ft_print()
    //t_stack *stack2 = ft_newlst(100);
    //ft_send_down(tail, lds[0], stack2);
    //ft_printlst(tail);
    //ft_printlst(stack2);
}
