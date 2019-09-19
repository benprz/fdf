/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 11:45:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 18:31:35 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_memdup(const void *s1, size_t n)
{
	size_t	i;
	char	*dst;

	if (!(dst = (void *)malloc(sizeof(void) * n)))
		return (NULL);
	i = 0;
	while (i != n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (dst);
}
