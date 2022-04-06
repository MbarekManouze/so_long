/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:56:01 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/05 18:20:06 by mmanouze         ###   ########.fr       */
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

void    xpm_to_image(t_var *var)
{
    int img_width;
    int img_height;

    var->img_collec = mlx_xpm_file_to_image(var->mlx, "./images/basketball.xpm", &img_width, &img_height);
    if (!var->img_collec)
        ft_error();
    var->img_space = mlx_xpm_file_to_image(var->mlx, "./images/background.xpm", &img_width, &img_height);
    if (!var->img_space)
        ft_error();
    var->img_door = mlx_xpm_file_to_image(var->mlx, "./images/door2.xpm", &img_width, &img_height);
    if (!var->img_door)
        ft_error();
    var->img_player = mlx_xpm_file_to_image(var->mlx, "./images/player.xpm", &img_width, &img_height);
    if (!var->img_player)
        ft_error();
    var->img_wall = mlx_xpm_file_to_image(var->mlx, "./images/wall.xpm", &img_width, &img_height);
    if (!var->img_wall)
        ft_error();
}

void    set_down_map(t_var *var)
{
    int i;
    int j;

    i = 0;
    while (var->two[i])
    {
        j = 0;
        while (var->two[i][j])
        {
            if (var->two[i][j] == '1')
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_wall, j * 64, i * 64);
            else if (var->two[i][j] == '0')
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_space, j * 64, i * 64);
            else if (var->two[i][j] == 'P')
            {
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_space, j * 64, i * 64);
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_player, j * 64, i * 64);
            }
            else if (var->two[i][j] == 'C')
            {
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_space, j * 64, i * 64);
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_collec, j * 64, i * 64);
            }
            else if (var->two[i][j] == 'E')
            {
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_space, j * 64, i * 64);
                mlx_put_image_to_window(var->mlx, var->mlx_win, var->img_door, j * 64, i * 64);
            }
            j++;
        }
        i++;
    }
}

void    check_map(char  *str)
{
    t_var   var;
    
    inis(&var);
    read_map(&var, str);
    up_down_walls(&var);
    side_walls(&var);
    map_elements(&var);
    var.mlx = mlx_init();
    var.mlx_win = mlx_new_window(var.mlx, var.length * 64, var.height * 64, "so_long");
    xpm_to_image(&var);
    set_down_map(&var);
    mlx_loop(var.mlx);
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