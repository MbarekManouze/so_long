/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:23:53 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/05 12:15:20 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct var
{
    char    **two;
    int     height;
    int     length;
    int     P;
    int     C;
    int     E;
    int     O_I;
    void    *mlx;
    void    *mlx_win;
    void    *img_wall;
    void    *img_player;
    void    *img_space;
    void    *img_door;
    void    *img_collec;
}   t_var;

char	*get_next_line(int fd);
int     ft_strlen(char *s);
size_t  ft_strchr(char *buffer);
char    *ft_substr(char *s, int start, int len);
char    *ft_strdup(const char	*s1);
char    *ft_strjoin(char	*s1, char	*s2);
int     ft_strcmp(const char	*s1, const char	*s2);
char    *ft_strchr_p(char *buffer);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	len);
void    ft_error(void);
void    read_map(t_var *var, char *str);
void    up_down_walls(t_var *var);
void    side_walls(t_var *var);
void    map_elements(t_var *var);

#endif