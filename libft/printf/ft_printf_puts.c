/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_puts.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 11:28:03 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/02/12 20:04:52 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putdi(va_list ptr_var)
{
	return (ft_putint(va_arg(ptr_var, int), 10, BASE10));
}

int	ft_putu(va_list ptr_var)
{
	return (ft_putluint(va_arg(ptr_var, unsigned int), 10, BASE10));
}

int	ft_putx(va_list ptr_var)
{
	return (ft_putluint(va_arg(ptr_var, unsigned int), 16, BASE16_L));
}

int	ft_put_capx(va_list ptr_var)
{
	return (ft_putluint(va_arg(ptr_var, unsigned int), 16, BASE16_U));
}

int	ft_put_lui(va_list ptr_var)
{
	return (ft_putluint(va_arg(ptr_var, long unsigned int), 10, BASE10));
}
