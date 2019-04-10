/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:59:29 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/09 19:54:23 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	int i;

	if (argc != 2)
	{
		ft_putstr("usage: fillit <file>\n");
		return (0);
	}
	tetread(argv[1]);
	while (1)
		i = 0;
	return (0);
}
