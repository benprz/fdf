/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:35:57 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:18:12 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i != len)
	{
		if (*src)
		{
			dst[i] = *src;
			src++;
		}
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
