/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:39:30 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 14:39:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_free(t_lists *d)
{
	d->errors = 1;
	if (d->big_line)
		free(d->big_line);
	if (d)
		free(d);
	exit(0);
}

void	ft_dead(t_lists *d)
{
	write(1, "You Lost The Elections\n", 23);
	ft_free(d);
}