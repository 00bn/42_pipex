/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:38:24 by balnahdi          #+#    #+#             */
/*   Updated: 2021/12/30 13:08:55 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include	"./libft/libft.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/uio.h>
# include	<stdlib.h>
# include	<sys/wait.h>
# include	<fcntl.h>
# include	<errno.h>

void	free_double(char **cmd);
char	*commands(char *cmd);

#endif