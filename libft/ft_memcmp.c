/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:39:53 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:00:53 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		while ((*((unsigned char *)s1) == *((unsigned char *)s2)) && n != 1)
		{
			s1++;
			s2++;
			n--;
		}
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	}
	return (0);
}
