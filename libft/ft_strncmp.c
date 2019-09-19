/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:41:51 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:18:22 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (len)
	{
		while (*s1 == *s2 && *s1 && len != 1)
		{
			s1++;
			s2++;
			len--;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
