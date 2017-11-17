/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:23 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:18:26 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "tetriminos.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && --n)
	{
		if (*s1 == '\0')
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int			is_in_list(char const *tetri)
{
	int i;

	i = 0;
	while (i < NB_BASICS)
	{
		if (!ft_strncmp(tetri, g_basics[i], 20))
			return (1);
		++i;
	}
	return (0);
}
