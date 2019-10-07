/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:35:09 by gmajstru          #+#    #+#             */
/*   Updated: 2018/09/20 17:27:53 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_word_num(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (str[i + 1] == '\0')
			break ;
		if (ft_isspace(str[i]) && !ft_isspace(str[i + 1]))
			count++;
		i++;
	}
	return (count + 1);
}

int		get_word_len(char *str, int index)
{
	int i;
	int len;

	len = 0;
	i = index;
	while (str[i] && !ft_isspace(str[i]))
	{
		len++;
		i++;
	}
	return (len);
}

void	fill_arr(char **tab, char *str)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		if (!(tab[count] = malloc(sizeof(char) * get_word_len(str, i))))
			return ;
		j = 0;
		while (str[i] && !ft_isspace(str[i]))
		{
			tab[count][j] = str[i];
			i++;
			j++;
		}
		tab[count][j] = 0;
		count++;
	}
	tab[count] = 0;
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = malloc((sizeof(char *) * get_word_num(str) + 1))))
		return (NULL);
	while (i < get_word_num(str))
	{
		fill_arr(tab, str);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
