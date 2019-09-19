/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 20:00:10 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 10:07:42 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# define DELIM '\n'

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft.h"

int					get_next_line(int fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	void			*content;
	size_t			size;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

#endif
