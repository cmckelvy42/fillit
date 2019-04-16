/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:59:29 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/04/15 12:41:50 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit <file>\n");
		return (0);
	}
	tetread(argv[1]);
	return (0);
}
