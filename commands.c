/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:10:43 by balnahdi          #+#    #+#             */
/*   Updated: 2021/12/30 13:12:20 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

char	*commands(char *cmd)
{
	int		i;
	char	*env;
	char	*dirs;
	char	**path;
	char	*pathslash;

	env = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:";
	path = ft_split(env, ':');
	i = 0;
	while (path[i])
	{
		pathslash = ft_strjoin(path[i], "/");
		dirs = ft_strjoin(pathslash, cmd);
		free(pathslash);
		if (access(dirs, F_OK) == 0)
			return (dirs);
		free(dirs);
		i++;
	}
	free_double(path);
	return (dirs);
}
