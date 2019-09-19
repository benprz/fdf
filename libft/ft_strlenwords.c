/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlenwords.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/26 15:20:29 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/08/26 15:25:14 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strlenwords(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	if (str[i] != ' ' && str[i] != '\t')
		words++;
	i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			if (str[i - 1] == ' ' || str[i - 1] == '\t')
				words++;
		i++;
	}
	return (words);
}
