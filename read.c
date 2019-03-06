/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:04:48 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/06 15:45:49 by cmckelvy         ###   ########.fr       */
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

/*void	verify(char **tets, size_t size)
{
	int		i;
	t_etris	*new;
	t_grid	*grid;

	map
}*/

void	pieces(char *str, size_t size)
{
	char	**tets;
	size_t	i;
	size_t	k;
	int		f;
	int		j;

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
	{
		tets[j] = ft_strnew(21);
		tets[j] = ft_strncpy(tets[j], &str[f], 20);
		tets[j][21] = '\0';
		//ft_putstr(tets[j]);
		j++;
		//ft_putchar('\n');
		f += 21;
	}
	tets[j] = NULL;
	ft_putstr("So far so good\n");
	//verify(tets, i);
}

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
	tfile = (char*)malloc((tsize + 1));
	fd = open(filename, O_RDONLY);
	read(fd, tfile, tsize);
	pieces(tfile, tsize);
	free(tfile);
}
