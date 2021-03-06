/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:40:23 by mcarc             #+#    #+#             */
/*   Updated: 2019/09/23 19:45:39 by mcarc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	size;

	i = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			f(&s[i]);
			i++;
		}
	}
}
