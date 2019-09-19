/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 10:57:42 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 11:18:03 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	if (str)
	{
		i = ft_strlen(str) - 1;
		j = 0;
		while (i > j)
		{
			c = str[i];
			str[i] = str[j];
			str[j] = c;
			i--;
			j++;
		}
		return (str);
	}
	return (NULL);
}
