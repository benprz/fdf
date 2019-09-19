/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:46:41 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:00:46 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}
