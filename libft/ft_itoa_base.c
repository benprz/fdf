/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 09:05:57 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 10:31:07 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static	int		count_chars_base(unsigned int nb, size_t base, int neg)
{
	int i;

	if (!nb || base < 2)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (neg && base == 10 ? i + 1 : i);
}

char			*ft_itoa_base(int n, size_t base)
{
	char			*str;
	int				neg;
	unsigned int	nb;
	int				tmp;
	int				nchars;

	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	neg = n < 0 ? 1 : 0;
	nchars = count_chars_base(nb, base, neg);
	str = NULL;
	if (base < 2 || !(str = (char *)malloc(sizeof(*str) * nchars + 1)))
		return (NULL);
	str[nchars] = '\0';
	if (!n)
		*str = '0';
	while (nb != 0)
	{
		tmp = nb % base;
		str[--nchars] = tmp > 9 ? (tmp - 10) + 'a' : tmp + '0';
		nb /= base;
	}
	if (neg && base == 10)
		*str = '-';
	return (str);
}
