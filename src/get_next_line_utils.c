/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:06:52 by joaoleote         #+#    #+#             */
/*   Updated: 2025/03/08 14:06:52 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_len(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}

char	*ft_strjoin_g(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_len(str) + ft_len(buffer) + 1);
	if (!new)
		return (0);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		new[i + j] = buffer [j];
		if (buffer[j++] == '\n')
			break ;
	}
	new[i + j] = '\0';
	free (str);
	return (new);
}

int	ft_newline(char *buffer, int i)
{
	char	*b;
	char	*t;

	b = buffer;
	t = buffer;
	while (*b)
	{
		if (*b == '\n')
		{
			i = 1;
			*b++ = '\0';
			break ;
		}
		*b++ = '\0';
	}
	if (i == 1)
	{
		while (*b)
		{
			*t++ = *b;
			*b++ = '\0';
		}
	}
	return (i);
}
