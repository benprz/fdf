/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 19:33:17 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 09:50:19 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*delete_node(t_gnl *node)
{
	t_gnl *tmp;

	if ((tmp = node))
	{
		if (!(node = tmp->prev))
			node = tmp->next;
		if (tmp->prev && tmp->next)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else if (tmp->prev)
			tmp->prev->next = NULL;
		else if (tmp->next)
			tmp->next->prev = NULL;
		if (tmp->size)
			free(tmp->content);
		free(tmp);
	}
	while (node && node->prev)
		node = node->prev;
	return (node);
}

t_gnl	*init_node(t_gnl *node, const int fd)
{
	t_gnl *tmp;

	tmp = NULL;
	while (node)
	{
		tmp = node;
		if (node->fd != fd)
			node = node->next;
		else
			break ;
	}
	if (!tmp || !node)
	{
		node = (t_gnl *)malloc(sizeof(t_gnl));
		node->fd = fd;
		node->content = NULL;
		node->next = NULL;
		node->size = 0;
		if (tmp)
			tmp->next = node;
		node->prev = tmp;
	}
	return (node);
}

int		read_content(t_gnl *node)
{
	char	*buff;
	char	*tmp;
	int		rlen;

	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (!(rlen = read(node->fd, buff, BUFF_SIZE)))
	{
		free(buff);
		return (0);
	}
	tmp = node->content;
	node->content = ft_memjoin(node->content, buff, node->size, rlen);
	if (!node->content)
		return (-1);
	node->size += rlen;
	free(tmp);
	free(buff);
	return (1);
}

t_gnl	*update_node(t_gnl *node, size_t i)
{
	char	*tmp;

	if (i + 1 >= node->size)
		return (delete_node(node));
	else
	{
		tmp = node->content;
		node->size -= i + 1;
		if (!(node->content = ft_memdup(node->content + i + 1, node->size)))
			return (delete_node(node));
		free(tmp);
	}
	while (node->prev)
		node = node->prev;
	return (node);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*gnl;
	int				ret;
	size_t			line_size;

	ret = 0;
	if (fd < 0 || !line || !(gnl = init_node(gnl, fd)))
		return (-1);
	while (!ft_memchr(gnl->content, DELIM, gnl->size))
	{
		if (!(ret = read_content(gnl)) || ret == -1)
			break ;
	}
	if (!gnl->size || ret == -1)
	{
		gnl = delete_node(gnl);
		return (ret == -1 ? -1 : 0);
	}
	line_size = ft_memlenchr(gnl->content, DELIM, gnl->size);
	if (!(*line = ft_strndup(gnl->content, line_size)))
	{
		gnl = delete_node(gnl);
		return (-1);
	}
	gnl = update_node(gnl, line_size);
	return (1);
}
