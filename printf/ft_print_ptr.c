/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:56:51 by alisharu          #+#    #+#             */
/*   Updated: 2025/01/30 20:42:57 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long value, int asc)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_print_hex(value, asc);
	return (count);
}
