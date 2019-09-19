/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 13:31:27 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 11:17:52 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	long	value;
	int		len;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if ((sign = *str == '-' ? -1 : 0) || *str == '+')
		str++;
	else if (!ft_isdigit(*str))
		return (0);
	value = 0;
	len = 0;
	while (ft_isdigit(*str))
	{
		value = value * 10 + (*str++ - 48);
		len++;
		if (len >= 19)
		{
			if (value < 0)
				return (sign == -1 ? 0 : -1);
		}
	}
	return (sign == -1 ? -value : value);
}
