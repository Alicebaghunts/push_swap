/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:54:22 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/14 20:05:56 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	free(line);
	return (str);
}
