/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:29:45 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 01:29:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include "get_next_line.h"
# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_lists
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*fond;
	void	*vote;
	void	*npc;
	void	*npcstart;
	void	*npcmv;
	void	*npcleft;
	void	*npclmv;
	void	*npcright;
	void	*npcrmv;
	void	*npcback;
	void	*npcbmv;
	void	*imgexit;
	void	*enemy_;
	void	*enemyst;
	void	*enemymv;
	int		spenemy;
	int		errors;
	int		moves;
	int		npccontrol;
	size_t	linecontrol;
	int		x;
	int		y;
	int		consum;
	int		ex;
	int		back;
	int		walls;
	int		player;
	int		enemy;
	int		height_l;
	size_t	width_l;
	char	*big_line;
}	t_lists;

int		main(int ac, char **av);
int		init_data(t_lists *d, char *map);
int		key_press(int key, t_lists *d);
int		check_exit(t_lists *d, char letter);
int		ft_free(t_lists *d);
void	print_map(t_lists *d);
void	read_map(char *map, t_lists *d);
void	ft_error(t_lists *d, int num);
void	change_sprite(t_lists *d, int num);
int		check_exit(t_lists *d, char letter);
void	ft_dead(t_lists *d);


#endif