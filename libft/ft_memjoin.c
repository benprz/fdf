/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 09:17:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 18:33:02 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_memjoin(void *s1, void *s2, size_t size, size_t size2)
{
	char *new;

	if (!(new = (void *)malloc(sizeof(void) * (size + size2))))
		return (NULL);
	if (size)
		ft_memcpy(new, s1, size);
	if (size2)
		ft_memcpy(new + (size ? size : 0), s2, size2);
	return (new);
}
