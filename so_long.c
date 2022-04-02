/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:56:01 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/02 15:45:57 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    inis(t_var *var)
{
    var->C = 0;
    var->E = 0;
    var->height = 0;
    var->length = 0;
    var->O_I = 0;
    var->P = 0;
}

void    check_map(char  *str)
{
    t_var   var;
    
    inis(&var);
    read_map(&var, str);
    up_down_walls(&var);
    side_walls(&var);
    map_elements(&var);
}

int main(int ac, char **av)
{
    char    *str;

    
    if (ac == 1)
        ft_error();
    str = ft_strchr_p(*(av + 1));
    if (!str)
        ft_error();
    if (ft_strcmp(str, ".ber") != 0)
        ft_error();
    check_map(*(av + 1));
}