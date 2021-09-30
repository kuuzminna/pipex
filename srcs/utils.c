/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrapefr <ggrapefr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:37:56 by ggrapefr          #+#    #+#             */
/*   Updated: 2021/09/30 16:19:05 by ggrapefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}

int	get_next_line(char **line)
{
	int		i;
	int		rd;
	char	ch;
	char	*buffer;

	i = 0;
	buffer = malloc(100000);
	if (!buffer)
		error();
	*line = buffer;
	write(1, "> ", 2);
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(0, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}
