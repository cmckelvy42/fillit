/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:50 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/10 12:54:48 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define FILLED(c)				((c - '#' == 0) ? 1 : -1)
# define EMPTY(c)				((c - '.' == 0) ? 1 : 0)
# define CHECK_BAD(x)			if (x) return (0)
# define VALID_CHAR(c)			((c == '#' || c == '.' || c == '\n') ? 1 : 0)


typedef struct		s_etris
{
	char			letter;
	int				x[4];
	int				y[4];
	struct s_etris	*next;
}					t_etris;

void				tetread(char *filename);
size_t				tetsize(int fd);
#endif
