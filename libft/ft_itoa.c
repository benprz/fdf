/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 11:11:40 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 11:43:58 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_chars(int n)
{
	int i;

	i = 0;
	if (!n)
		return (i + 1);
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				nchars;
	int				neg;

	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	nchars = count_chars(n);
	if (!(str = (char *)malloc(sizeof(char *) * nchars + 1)))
		return (NULL);
	str[nchars] = '\0';
	nchars--;
	neg = n < 0 ? 1 : 0;
	if (!n)
		*str = '0';
	while (nb)
	{
		str[nchars] = (nb % 10) + '0';
		nb /= 10;
		nchars--;
	}
	if (neg)
		*str = '-';
	return (str);
}
