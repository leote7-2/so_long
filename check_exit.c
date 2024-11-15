/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:08 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 16:07:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	check_exit(t_lists *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "CONGRATULATIONS, You Won The Elections! :)))\n", 45);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "You need to colect all the Votes!\n", 34);
		return (1);
	}
	else
		return (0);
}