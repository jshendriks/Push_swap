/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 12:27:07 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/02/12 20:05:37 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

# define BASE10 "0123456789"
# define BASE16_L "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"
# define SPECS "cspdiuxXL"

typedef int	(*t_function)(va_list);
int	ft_strchr_i(const char *str, char c);
int	ft_putchar_wrt(va_list ptr_var);
int	ft_putstr_wrt(va_list ptr_var);
int	ft_putptr(va_list ptr_var);
int	ft_putdi(va_list ptr_var);
int	ft_putu(va_list ptr_var);
int	ft_putx(va_list ptr_var);
int	ft_put_capx(va_list ptr_var);
int	ft_put_lui(va_list ptr_var);
int	ft_putint(int n, int base, char *str_base);
int	ft_putluint(long unsigned int n, int base, char *str_base);
int	ft_printf(const char *str, ...);
int	select_function(int i, va_list ptr_var);

#endif
