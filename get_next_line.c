/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:13:50 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 01:13:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buffer);
		if (ft_newline(buffer, 0))
			break ;
	}
	return (str);
}

/*int	main(void)
{
	int	fd;
	char	*str;

	fd = open("ola.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}*/
