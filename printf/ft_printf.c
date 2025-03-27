/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:32:51 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/31 16:29:35 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_print_usd(va_arg(args, unsigned int));
	else if (type == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long), 0);
	else if (type == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (type == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int			count;
	va_list		args;
	const char	*ptr;

	count = 0;
	ptr = input;
	va_start(args, input);
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) != '\0')
		{
			count += handle_format(*(ptr + 1), args);
			if (count == -1)
				return (-1);
			ptr++;
		}
		else
			count += ft_putchar(*ptr);
		if (count == -1)
			return (-1);
		ptr++;
	}
	va_end(args);
	return (count);
}
