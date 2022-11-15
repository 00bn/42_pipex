/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:10:35 by balnahdi          #+#    #+#             */
/*   Updated: 2021/12/30 13:20:27 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int fd, int ends[2], char *argv[])
{
	int		err;
	char	*exe;
	char	**cmd;

	if (access(argv[1], F_OK) == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	cmd = ft_split(argv[2], ' ');
	exe = commands(cmd[0]);
	close(ends[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(errno);
	if (dup2(ends[1], STDOUT_FILENO) == -1)
		exit(errno);
	close(ends[1]);
	err = execve(exe, cmd, 0);
	close(fd);
	if (err == -1)
	{
		free_double(cmd);
		perror("first command not found ");
		exit(127);
	}
}

void	parent(int fd, int ends[2], char *argv[])
{
	int		err;
	char	**cmd;
	char	*exe;

	cmd = ft_split(argv[3], ' ');
	exe = commands(cmd[0]);
	close(ends[1]);
	if (dup2(ends[0], STDIN_FILENO) == -1)
		exit(errno);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(errno);
	close(ends[0]);
	err = execve(exe, cmd, 0);
	close(fd);
	if (err == -1)
	{
		free_double(cmd);
		perror("second command not found ");
		exit(127);
	}
}

void	split_process(char *argv[], int fd[], int ends[])
{
	pid_t	child1;
	int		status;

	child1 = fork();
	if (child1 == 0)
		first_child(fd[0], ends, argv);
	else
	{
		waitpid(-1, &status, 0);
		parent(fd[1], ends, argv);
	}
}

int	main(int argc, char *argv[])
{
	int	ends[2];
	int	fd[2];

	if (argc == 5)
	{
		fd[0] = open(argv[1], O_RDWR);
		fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd[1] == -1)
			exit(errno);
		if (pipe(ends) < 0)
			perror("pipe not created ");
		split_process(argv, fd, ends);
	}
	else
	{
		write(1, "wrong number of arguments\n", 27);
		exit(1);
	}
}
