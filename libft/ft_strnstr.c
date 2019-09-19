/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:54:21 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:09:38 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	clen;

	i = -1;
	j = 0;
	k = 0;
	clen = len;
	while (s1[++i] && clen)
	{
		if (s1[i] == s2[j])
		{
			if (++j == ft_strlen(s2))
				return ((char *)s1 + i - j + 1);
		}
		else
		{
			j = 0;
			clen = len - k;
			i = k++;
		}
		clen--;
	}
	return (*s2 ? NULL : (char *)s1);
}
