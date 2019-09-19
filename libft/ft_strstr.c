/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:58:46 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:27:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if (*s2 && !(s1 = ft_strchr(s1, *s2)))
			return (NULL);
		while (s1[i] == s2[i] && s1[i])
			i++;
		if (i == ft_strlen(s2))
			return ((char *)s1);
		else
		{
			i = 0;
			s1++;
		}
	}
	return (*s2 ? NULL : (char *)s1);
}
