/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_overflow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhendrik <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 11:07:06 by jhendrik      #+#    #+#                 */
/*   Updated: 2023/03/21 17:48:32 by jhendrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static int	rec_atoi(const char *str, int nb, int sgn, int *flw);

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	process_cdigit(const char *str, int nb, int sgn, int *flw)
{	
	if (sgn == 1 || sgn == 0)
	{
		if (nb * 10 + (*str - '0') < 0)
		{
			*flw = 0;
			return (nb);
		}
		return (rec_atoi(str + 1, nb * 10 + (*str - '0'), 1, flw));
	}
	else if (nb * 10 - (*str - '0') > 0)
	{
		*flw = 0;
		return (nb);
	}
	return (rec_atoi(str + 1, nb * 10 - (*str - '0'), sgn, flw));
}

static int	rec_atoi(const char *str, int nb, int sgn, int *flw)
{
	if (*str == '\0')
		return (nb);
	else if (ft_isspace(*str) == 1)
	{
		if (sgn != 0 || nb != 0)
			return (nb);
		return (rec_atoi(str + 1, nb, sgn, flw));
	}
	else if (*str == '-' || *str == '+')
	{
		if (*str == '-' && sgn == 0)
			return (rec_atoi(str + 1, nb, -1, flw));
		else if (*str == '+' && sgn == 0)
			return (rec_atoi(str + 1, nb, 1, flw));
		else
			return (nb);
	}
	else if (*str >= '0' && *str <= '9')
		return (process_cdigit(str, nb, sgn, flw));
	else
		return (nb);
}

int	ft_atoi_overflw(const char *str, int *ptr_num)
{
	int	nb;
	int	flw;
	int	*ptr_flw;

	flw = 1;
	ptr_flw = &flw;
	if (str == NULL)
		return (0);
	nb = rec_atoi(str, 0, 0, ptr_flw);
	*ptr_num = nb;
	return (flw);
}
