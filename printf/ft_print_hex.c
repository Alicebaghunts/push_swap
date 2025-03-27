/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:21 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/31 20:18:41 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_hex(char *hex_set, int asc)
{
	int		i;
	char	c;
	char	*set;

	set = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		c = set[i];
		if (asc && c >= 'a' && c <= 'z')
			c ^= 32;
		hex_set[i] = c;
		i++;
	}
	hex_set[i] = 0;
}

int	ft_print_hex(size_t value, int asc)
{
	char	hex_digits[16];
	int		count;
	char	hex_set[17];
	int		i;

	i = 0;
	count = 0;
	fill_hex(hex_set, asc);
	if (value == 0)
	{
		return (ft_putchar('0'));
	}
	while (value != 0)
	{
		hex_digits[i++] = hex_set[value % 16];
		value /= 16;
	}
	while (i--)
		count += ft_putchar(hex_digits[i]);
	return (count);
}
