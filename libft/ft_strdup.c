/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:32:05 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:14:45 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*dst;

	i = ft_strlen(s1);
	dst = NULL;
	if (!(dst = (char *)malloc(sizeof(*dst) * i + 1)))
		return (dst);
	j = 0;
	while (j != i)
	{
		dst[j] = s1[j];
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
