/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:13:29 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:16:50 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	s2 = NULL;
	if (s && f)
	{
		if (!(s2 = ft_strnew(ft_strlen(s))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			s2[i] = f(s[i]);
			i++;
		}
	}
	return (s2);
}
