/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:55:54 by gmajstru          #+#    #+#             */
/*   Updated: 2018/09/04 15:33:06 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_get_filedes(t_list **begin, int fd)
{
	t_list	*ptr;

	ptr = *begin;
	while (ptr)
	{
		if (fd == (int)ptr->content_size)
			return (ptr);
		ptr = ptr->next;
	}
	ptr = ft_lstnew("\0", 1);
	ptr->content_size = fd;
	ft_lstadd(begin, ptr);
	return (ptr);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*ptr;
	t_list			*begin;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = ptr;
	ptr = ft_get_filedes(&begin, fd);
	while (!ft_strchr(ptr->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		ptr->content = ft_strnjoin_free(ptr->content, buf, ret, 'L');
	ret = 0;
	while (((char*)ptr->content)[ret] && ((char*)ptr->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(ptr->content, ret);
	(((char*)ptr->content)[ret] == '\n') ? ++ret : 0;
	tmp = ptr->content;
	ptr->content = ft_strdup(tmp + ret);
	ptr = begin;
	free(tmp);
	return (ret ? 1 : 0);
}
