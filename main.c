/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:59:29 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/10 22:50:40 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	int i = 0;

	if (argc != 2)
	{
		ft_putstr("usage: fillit <file>\n");
		return (0);
	}
	tetread(argv[1]);
	return (0);
}
