/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maddi <maddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 07:03:07 by maddi             #+#    #+#             */
/*   Updated: 2022/04/03 16:09:56 by maddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_checkdups(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (ft_atoi(av[j]) == ft_atoi(av[i]))
            {
                ft_putstr_fd("Error\n", 2);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

static int ft_strisnum(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit((char)str[i]))
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

static int ft_checktype(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (!ft_strisnum(av[i]))
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
}

static int ft_checkoverflow(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (ft_atol(av[i]) > INT_MAX)
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        i++;
    }
    return (1);
    
}

int ft_checkargs(int ac, char **av)
{
    if (ac == 1 || av == NULL)
        return (0);
    else if (!ft_checkdups(av) || !ft_checkoverflow(av) || !ft_checktype(av))
        return (0);
    else
        return (1);
}
