/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 09:52:08 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 12:59:57 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (dst + i);
		i++;
	}
	if (s[i] == c)
		return (dst + i);
	return (NULL);
}
