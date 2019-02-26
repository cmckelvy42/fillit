/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:04:48 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/26 14:30:03 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	tetsize(int fd)
{
	size_t	i;
	char	buf[1];

	i = 0;
	while (read(fd, buf, 1))
		i++;
	close (fd);
	return (i);
}

/*void	pieces(char *str, size_t size)
{
	char	**tets;
	int		i;
	int		j;
	int		f;
	int		k;

	if (!(tets = (char**)malloc(sizeof(char*) * ((size / 20) + 1))))
	{
		ft_putstr("Error");
		return ;
	}
	k = size % 20;
	i = size / 20;
	j = 0;
	f = 0;
	if (!(i == k + 1) || i > 26)
	{
		ft_putstr("Error");
		return ;
	}
	while (j < i)

}*/

void	tetread(char *filename)
{
	int			fd;
	char		*tfile;
	size_t		tsize;


	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: invalid file\n");
		return ;
	}
	tsize = tetsize(fd);
	tfile = ft_strnew(tsize);
	fd = open(filename, O_RDONLY);
	read(fd, tfile, tsize);
	//pieces(tfile, tsize);
	free(tfile);
}
