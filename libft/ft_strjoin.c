/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:53:07 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:15:58 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	if (!s1 || !s2 || !(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (s3 && s1)
			s3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		if (s3 && s2)
			s3[i] = *s2;
		i++;
		s2++;
	}
	return (s3);
}
