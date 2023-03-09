/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_jump.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 15:38:06 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/02/12 20:06:19 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	select_function(int i, va_list ptr_var)
{
	t_function	jmptbl[9];

	jmptbl[0] = &ft_putchar_wrt;
	jmptbl[1] = &ft_putstr_wrt;
	jmptbl[2] = &ft_putptr;
	jmptbl[3] = &ft_putdi;
	jmptbl[4] = &ft_putdi;
	jmptbl[5] = &ft_putu;
	jmptbl[6] = &ft_putx;
	jmptbl[7] = &ft_put_capx;
	jmptbl[8] = &ft_put_lui;
	return (jmptbl[i](ptr_var));
}
