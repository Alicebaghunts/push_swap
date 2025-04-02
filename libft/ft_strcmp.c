/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-02 10:26:10 by alisharu          #+#    #+#             */
/*   Updated: 2025-04-02 10:26:10 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_zero(char *str1)
{
	int	i;

	i = 0;
	if (str1[i] == '-' || str1[i] == '+')
		i++;
	while (str1[i] != '\0' && str1[i] == '0')
		i++;
	if (str1[i] == '\0')
		return (0);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+' && (s2[j] >= '1' && s2[j] <= '9'))
		i++;
	else if ((s1[i] == '-') && (s2[j] == '-'))
	{
		i++;
		j++;
	}
	if (s2[0] == '0' && s2[1] == '\0')
	{
		if (check_zero(s1) == 0)
			return (0);
	}
	if (s1[i] == '0')
		while (s1[i] != '\0' && s1[i] == '0')
			i++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i++] == s2[j])
		j++;
	return (s1[i] - s2[j]);
}
