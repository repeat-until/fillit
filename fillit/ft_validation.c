/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:00:25 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/03/12 23:58:05 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_fillit.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFF_SIZE 1

/*int	ft_write_file(int fd, char **l)
{
	char	*tmp;
	int		count;
	char	buf[BUFF_SIZE + 1];

	*l = ft_strnew(0);
	if ((fd < 0 || read(fd, buf, 0) < 0 || !l))
		return (-1);
	while ((count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[count] = '\0';
		tmp = ft_strjoin(*l, buf);
		free(*l);
		*l = ft_strdup(tmp);
		free(tmp);
	}
	return (0);
}*/

char	valid_tetrim_2(char *s)
{
	int i;

	i = 0;
	while (s[i] != '#')
			i++;
	if (s[i + 4] == '#' && (s[i + 10] == '#' || s[i + 3] == '#' || s[i + 9] == '#'))
		return ('m');
	if (s[i + 6] == '#' && (s[i + 10] == '#' || s[i + 7] == '#' || s[i + 11] == '#'))
		return ('m');
	if (s[i + 10] == '#' && (s[i + 11] == '#' ||s[i + 9] == '#'))
		return ('m');
	if (s[i + 4] == '#' && s[i + 9] == '#')
		return ('m');
	if (s[i + 10] == '#' && s[i + 15] == '#')
		return ('m');
	return ('z');
}

char	valid_tetrim_1(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '#')
		i++;
	if (s[i + 1] == '#')
	{
		if (s[i + 2] == '#' && (s[i + 3] == '#' || s[i + 5] == '#' || s[i + 6] == '#' || s[i + 7] == '#'))
			return ('g');
		if (s[i + 5] == '#' && (s[i + 6] == '#' ||s[i + 4] == '#' || s[i + 10] == '#'))
			return ('f');
		if (s[i + 6] == '#' && (s[i + 11] == '#' || s[i + 7] == '#'))
			return ('i');
	}
	return (valid_tetrim_2(s));
}

int	valid_size_hash(char *l)
{
	int	i;
	int	hash;
	int point;

	i = -1;
	hash = 0;
	point = 0;
	while (++i < 19)
	{
		if (l[i] == '#')
			hash++;
		if (l[i] == '.')
			point++;
	}
	if (hash != 4 || point != 12)
		return (-1);
	if (l[19] != '\n' || l[14] != '\n' ||
			l[9] != '\n' || l[4] != '\n')
		return (-1);
	if (!l[20])
		return (0);
	if (l[20] != '\n')
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*tmp;
	int		check;
	int		numb;
	int		fd;
	int 	ret;

	numb = 1;
	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		tmp = ft_strnew(22);
		while ((ret = read(fd, tmp, 21)) > 0)
		{
			tmp[ret] = '\0';
			if (numb > 26)
			{
				printf("error_test\n");
				return (-1);
			}
			check = valid_size_hash(tmp);
			if (check == -1)
			{
				printf("error_test\n");
				return (-1);
			}
			if (valid_tetrim_1(tmp) == 'z')
			{
				printf("error_tetrim\n");
				return (-1);
			}
			else if (check == 0)

				return (0);
			numb += 1;
		}
	}
	printf("net_faila_ili_dva\\n_v_konce");
	printf("\n");
	return (-1);
}
