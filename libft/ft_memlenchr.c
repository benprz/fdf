/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memlenchr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 10:31:10 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 09:27:08 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

size_t		ft_memlenchr(const void *str, char c, size_t size)
{
	size_t i;

	i = 0;
	while (i != size && (((unsigned char *)str)[i] != (unsigned char)c))
		i++;
	return (i);
}
