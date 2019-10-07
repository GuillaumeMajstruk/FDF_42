/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 21:17:16 by gmajstru          #+#    #+#             */
/*   Updated: 2018/09/27 00:00:30 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_u_int	get_tab_width(char **tab)
{
	t_u_int size;

	size = 0;
	while (*tab++)
		size++;
	return (size);
}

int		str_is_digit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	add_pt_to_lst(t_list **lst, char **tab)
{
	int i;
	int val;

	i = 0;
	val = 0;
	while (tab[i])
	{
		if (!str_is_digit(tab[i]))
			on_init_error_exit(FILE_DIGITS_ERROR, EXIT_FAILURE);
		val = ft_atoi(tab[i]);
		ft_lst_pushback(lst, ft_lstnew(&val, sizeof(int)));
		i++;
	}
}

t_list	*check_input_file(char const *file_name, t_dim *tab_dim)
{
	char	*line;
	int		ret;
	int		fd;
	char	**tab;
	t_list	*altitude_lst;

	tab_dim->height = 0;
	tab_dim->width = 0;
	altitude_lst = NULL;
	if (!ft_strstr(file_name, ".fdf"))
		on_init_error_exit(FILE_EXT_ERROR, EXIT_FAILURE);
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		on_init_error_exit(FILE_OPEN_ERROR, EXIT_FAILURE);
	while ((ret = get_next_line(fd, &line)))
	{
		tab = ft_split_whitespaces(line);
		if (get_tab_width(tab) <= 1 ||
		(tab_dim->width && get_tab_width(tab) != tab_dim->width))
			return (NULL);
		else
			tab_dim->width = get_tab_width(tab);
		tab_dim->height++;
		add_pt_to_lst(&altitude_lst, tab);
	}
	return (altitude_lst);
}
