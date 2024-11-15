/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:25:37 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 15:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	change_sprite(t_lists *d, int num)
{
	int	change;

	change = 0;
	if (num == 0)
	{
		if (d->npccontrol == 0)
		{
			d->npccontrol = 1;
			change++;
		}
		if (d->npccontrol == 1 && change == 0)
			d->npccontrol = 0;
	}
	if (d->spenemy == 0)
	{
		d->enemyst = d->enemy_;
		d->spenemy = 1;
		change = 2;
	}
	if (d->spenemy == 1 && change != 2)
	{
		d->enemyst = d->enemymv;
		d->spenemy = 0;
	}
}
