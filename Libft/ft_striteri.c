/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:54:22 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/05/01 15:14:35 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**@brief Applies the function f on each character of the string
 * @param *s The string where it will be applied
 * @param *f Function to apply to each character
 * @return Nothing
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	print_index_and_character(unsigned int index, char *character)
{
	printf("Índice: %u, Caractere: %c\n", index, *character);
}
int main()
{
	char str[] = "Hello";

	ft_striteri(str, &print_index_and_character);
	return (0);
}*/