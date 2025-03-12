/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:06:10 by joaoleote         #+#    #+#             */
/*   Updated: 2025/03/12 16:39:43 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_line_size(int line_size, t_d *d, char *line, int fd)
{
	if (!d->map.width)
		d->map.width = line_size;
	else if (line_size != d->map.width)
	{
		free(line);
		close(fd);
		error_handler(2, d);
	}
}

void	flood_clean(t_d *d)
{
	free(d->assets.coins_existance);
	free(d->assets.c_pos);
	free(d->assets.enemies_pos);
	clean_matrix(d);
	exit(0);
}
