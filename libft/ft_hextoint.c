/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hextoint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/09 18:00:15 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/09/17 18:22:41 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_hextoint(char *str)
{
	int i;
	int base;
	int	dec;

	i = ft_strlen(str);
	base = 1;
	dec = 0;
	while (i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			dec += (str[i] - 48) * base;
			base *= 16;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			dec += (str[i] - 55) * base;
			base *= 16;
		}
	}
	return (dec);
}
