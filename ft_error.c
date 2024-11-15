/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:15:55 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 14:15:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_errors(t_lists *d, int num)
{
	d->moves++;
	d->moves--;
	if (num == 8)
		write(1, "The Characters in the map are wrong\n", 36);
	if (num == 9)
		write(1, "The map isn't rectangular", 26);
}

void	ft_error(t_lists *d, int num)
{
	write(1, "ERROR\n", 6);
	if (num > 7)
		ft_errors(d, num);
	if (num == 1)
		write(1, "There is no walls in the beggining of the line\n", 47);
	if (num == 2)
		write(1, "There is no walls in the ending of the line\n", 44);
	if (num == 3)
		write(1, "There is no walls in the first line\n", 36);
	if (num == 4)
		write(1, "There is no walls on the last line\n", 35);
	if (d->consum && num == 5)
		write(1, "There is no consumables\n", 24);
	if (d->player && num == 5)
		write(1, "The map doesn't have a player\n", 30);
	if (d->ex && num == 5)
		write(1, "The map doens't have an exit\n", 29);
	if (num == 6)
		write(1, "The file doesn't have the correct extension\n", 44);
	if (num == 7)
		write(1, "The map isn't rectangular\n", 26);
	ft_free(d);
}
