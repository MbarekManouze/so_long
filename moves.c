/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:54:52 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/08 13:39:32 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_right(t_var *var)
{
	if (var->two[var->x][var->y + 1] == '0' ||
			var->two[var->x][var->y + 1] == 'C')
	{
		if (var->two[var->x][var->y + 1] == 'C')
			var->c--;
		var->two[var->x][var->y] = '0';
		var->two[var->x][var->y + 1] = 'P';
		var->count++;
		set_down_map(var);
		ft_write_to_window(var);
	}
	else if (var->two[var->x][var->y + 1] == 'E' && var->c == 0)
	{
		printf("YOU WON\n");
		exit (0);
	}
}

void	ft_move_left(t_var *var)
{
	if (var->two[var->x][var->y - 1] == '0' ||
			var->two[var->x][var->y - 1] == 'C')
	{
		if (var->two[var->x][var->y - 1] == 'C')
			var->c--;
		var->two[var->x][var->y] = '0';
		var->two[var->x][var->y - 1] = 'P';
		var->count++;
		set_down_map(var);
		ft_write_to_window(var);
	}
	else if (var->two[var->x][var->y - 1] == 'E' && var->c == 0)
	{
		printf("YOU WON\n");
		exit (0);
	}
}

void	ft_move_up(t_var *var)
{
	if (var->two[var->x - 1][var->y] == '0' ||
			var->two[var->x - 1][var->y] == 'C')
	{
		if (var->two[var->x - 1][var->y] == 'C')
			var->c--;
		var->two[var->x][var->y] = '0';
		var->two[var->x - 1][var->y] = 'P';
		var->count++;
		set_down_map(var);
		ft_write_to_window(var);
	}
	else if (var->two[var->x - 1][var->y] == 'E' && var->c == 0)
	{
		printf("YOU WON\n");
		exit (0);
	}
}

void	ft_move_down(t_var *var)
{
	if (var->two[var->x + 1][var->y] == '0' ||
			var->two[var->x + 1][var->y] == 'C')
	{
		if (var->two[var->x + 1][var->y] == 'C')
			var->c--;
		var->two[var->x][var->y] = '0';
		var->two[var->x + 1][var->y] = 'P';
		var->count++;
		set_down_map(var);
		ft_write_to_window(var);
	}
	else if (var->two[var->x + 1][var->y] == 'E' && var->c == 0)
	{
		printf("YOU WON\n");
		exit (0);
	}
}

int	key_manager(int key, t_var *var)
{
	if (key == 53)
		exit (0);
	if (key == 124 || key == 2)
		ft_move_right(var);
	if (key == 0 || key == 123)
		ft_move_left(var);
	if (key == 126 || key == 13)
		ft_move_up(var);
	if (key == 125 || key == 1)
		ft_move_down(var);
	return (0);
}
