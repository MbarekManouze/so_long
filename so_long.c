/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:56:01 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/08 17:13:27 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inis(t_var *var)
{
	var->c = 0;
	var->e = 0;
	var->height = 0;
	var->length = 0;
	var->o_i = 0;
	var->p = 0;
	var->count = 0;
}

void	check_map(char *str)
{
	t_var	var;

	inis(&var);
	read_map(&var, str);
	up_down_walls(&var);
	side_walls(&var);
	map_elements(&var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.length * 64,
			var.height * 64, "so_long");
	xpm_to_image(&var);
	set_down_map(&var);
	mlx_hook(var.win, 17, 0L, do_func, &var);
	mlx_key_hook(var.win, key_manager, &var);
	mlx_loop(var.mlx);
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 1)
		ft_error();
	str = ft_strchr_p(*(av + 1));
	if (!str)
		ft_error();
	if (ft_strcmp(str, ".ber") != 0)
		ft_error();
	check_map(*(av + 1));
	system("leaks so_long");
}
