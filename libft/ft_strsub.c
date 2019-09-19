/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:04:32 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:10:25 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	s2 = NULL;
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i != len)
	{
		if (s2 && s)
			s2[i] = s[start];
		start++;
		i++;
	}
	return (s2);
}
