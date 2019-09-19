/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 17:29:32 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:23:34 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dst;

	dst = NULL;
	if (!(dst = (char *)malloc(sizeof(*dst) * n + 1)))
		return (dst);
	i = 0;
	while (i != n)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
