/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 20:05:32 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:16:11 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	if (size <= dlen + slen)
	{
		ft_memcpy(dst + dlen, src, size - dlen - 1);
		dst[size - 1] = '\0';
	}
	else
		ft_memcpy(dst + dlen, src, slen + 1);
	return (dlen + slen);
}
