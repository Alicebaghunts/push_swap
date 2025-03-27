/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:00:07 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/24 21:31:02 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char    *ft_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *new_str = (char *)malloc(len + 1);
    if (!new_str)
        return NULL;
    for (size_t i = 0; i < len; i++)
        new_str[i] = s[i];
    new_str[len] = '\0';
    return new_str;
}
