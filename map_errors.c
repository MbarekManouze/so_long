/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:06:51 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/02 15:31:48 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void    read_map(t_var *var, char *str)
{
    int     fd;
    char    *map;
    char    *take;

    take = NULL;
    fd = open(str, O_RDONLY);
    if (fd < 0)
        ft_error();
    map = get_next_line(fd);
    var->length = ft_strlen(map) - 1;
    take = ft_strjoin(take, map);
    while (map)
    {
        var->height++;
        if (ft_strcmp(map, "\n") == 0)
            ft_error();
        take = ft_strjoin(take, map);
        map = get_next_line(fd);
    }
     var->two = ft_split(take, '\n');
}

void    up_down_walls(t_var *var)
{
    int i;
    int a;

    a = 0;
    i = 0;
    while (var->two[0][i] == '1')
        i++;
    while (var->two[var->height][a] == '1')
        a++;
    if (i != var->length || a != var->length)
        ft_error();
}

void    side_walls(t_var *var)
{
    int i;
    int k;

    k = 0;
    i = var->height;
    while (i)
    {
        if (var->two[i][0] == '1' && var->two[i][var->length - 1] == '1')
            k++;
        i--;
    }
    if (k != var->height)
        ft_error();
}

void    map_elements(t_var *var)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (var->two[i][j])
    {
        if (var->two[i][j] == 'P')
            var->P++;
        else if (var->two[i][j] == 'C')
            var->C++;
        else if (var->two[i][j] == 'E')
            var->E++;
        else if (var->two[i][j] == '1' || var->two[i][j] == '0')
            var->O_I++;
        j++;
        if (j == var->length && var->two[i + 1])
        {
            i++;
            j = 0;
        }
    }
    if (var->P != 1 || var->C == 0 || var->E == 0)
        ft_error();
}
