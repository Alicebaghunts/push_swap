/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:43:24 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:54 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_malloc(int size)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	return (ptr);
}

int	foo(char **ptr, char const *s, char c)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	start = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ptr[index] = ft_substr(s, start, i - start);
		if(!ptr[index])
		{
			while (index > 0)
                free(ptr[--index]);
            return (index);
        }
        index++;
    }
    return (index);
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return (NULL);
        
    int word = word_count(s, c);
    char **ptr = ft_malloc(word);
    if (!ptr)
        return (NULL);
    int index = foo(ptr, s, c);
    if (index < word)
    {
        free(ptr);
        return (NULL);
    }
    ptr[index] = NULL;
    return (ptr);
}