/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:32:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 15:32:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	move_w(t_lists *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - d->width_l] != '1' &&
		!check_exit(d, d->big_line[i - d->big_line[i - d->width_l]]))
	{
		if (d->big_line[i - d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i - d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - d->width_l] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npcback;
		else
			d->npcstart = d->npcbmv;
	}
	print_map(d);
}

void	move_s(t_lists *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i + d->width_l] != '1' &&
		!check_exit(d, d->big_line[i + d->width_l]))
	{
		if (d->big_line[i + d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i + d->width_l] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + d->width_l] = 'P';
		change_sprite(d, 0);
		if (d->npccontrol == 0)
			d->npcstart = d->npc;
		else
			d->npcstart = d->npcbmv;
	}
	print_map(d);
}

void	move_a(t_lists *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i - 1]))
	{
		if (d->big_line[i + d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i - 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i - 1] = 'P';
		if (d->npccontrol == 0)
			d->npcstart = d->npcleft;
		else
			d->npcstart = d->npclmv;
	}
	print_map(d);
}

void	move_d(t_lists *d)
{
	int	i;

	i = 0;
	while (d->big_line[i] != 'P')
		i++;
	if (d->big_line[i - 1] != '1' && !check_exit(d, d->big_line[i + 1]))
	{
		if (d->big_line[i + d->width_l] == 'X')
			ft_dead(d);
		d->moves++;
		if (d->big_line[i + 1] == 'C')
			d->consum--;
		d->big_line[i] = '0';
		d->big_line[i + 1] = 'P';
		if (d->npccontrol == 0)
			d->npcstart = d->npcright;
		else
			d->npcstart = d->npcrmv;
	}
	print_map(d);
}

int	key_press(int key, t_lists *d)
{
	char	*player_moves;

	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	if (key == 13)
		move_w(d);
	if (key == 0)
		move_a(d);
	if (key == 1)
		move_s(d);
	if (key == 2)
		move_d(d);
	player_moves = ft_itoa(d->moves);
	mlx_string_put(d->mlx, d->win, d->x - 70, d->y - 20, 0x00000, "MOVES;");
	mlx_string_put(d->mlx, d->win, d->x - 30, d->y - 20, 0x00000, player_moves);
	write(1, player_moves, ft_strlen(player_moves));
	if (player_moves)
		free(player_moves);
	write(1, "\n", 1);
	return (0);
}
