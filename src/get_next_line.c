/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:06:45 by joaoleote         #+#    #+#             */
/*   Updated: 2025/03/08 14:06:45 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_g(str, buffer);
		if (ft_newline(buffer, 0))
			break ;
	}
	return (str);
}
