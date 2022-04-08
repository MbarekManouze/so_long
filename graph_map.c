/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:59:36 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/08 16:01:22 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image(t_var *var)
{
	int	wid;
	int	hei;

	var->img_c = mlx_xpm_file_to_image(var->mlx, "./im/bas.xpm", &wid, &hei);
	if (!var->img_c)
		ft_error();
	var->img_s = mlx_xpm_file_to_image(var->mlx, "./im/bac.xpm", &wid, &hei);
	if (!var->img_s)
		ft_error();
	var->img_d = mlx_xpm_file_to_image(var->mlx, "./im/d.xpm", &wid, &hei);
	if (!var->img_d)
		ft_error();
	var->img_p = mlx_xpm_file_to_image(var->mlx, "./im/p.xpm", &wid, &hei);
	if (!var->img_p)
		ft_error();
	var->img_w = mlx_xpm_file_to_image(var->mlx, "./im/w.xpm", &wid, &hei);
	if (!var->img_w)
		ft_error();
}

void	extra(t_var *var, int i, int j)
{
	var->x = i;
	var->y = j;
	mlx_put_image_to_window(var->mlx, var->win, var->img_p, j * 64, i * 64);
}

void	norm(t_var *var, int i, int j)
{
	if (var->two[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img_w, j * 64, i * 64);
	else if (var->two[i][j] == '0' || var->two[i][j] == 'P'
		|| var->two[i][j] == 'C' || var->two[i][j] == 'E')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img_s, j * 64, i * 64);
	if (var->two[i][j] == 'P')
		extra(var, i, j);
	if (var->two[i][j] == 'C')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img_c, j * 64, i * 64);
	if (var->two[i][j] == 'E')
		mlx_put_image_to_window(var->mlx, var->win,
			var->img_d, j * 64, i * 64);
}

void	set_down_map(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->two[i])
	{
		j = 0;
		while (var->two[i][j])
		{
			norm(var, i, j);
			j++;
		}
		i++;
	}
}

void	ft_write_to_window(t_var *var)
{
	char	*str;

	ft_printf("move : %d\n", var->count);
	str = ft_itoa(var->count);
	mlx_string_put(var->mlx, var->win, 25, 25, 0xccccff, str);
	free(str);
}
