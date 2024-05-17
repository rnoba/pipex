/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:00:41 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:09 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pipex.h>

const char	*ft_get_path(char *env[])
{
	while (*env)
	{
		if (0 == ft_strncmp("PATH=", *env, 5))
			return (ft_strchr(*env, '=') + 1);
		env++;
	}
	return (NULL);
}

void	ft_free_matrix(char **m)
{
	size_t	idx;

	idx = 0;
	while (m[idx])
		free(m[idx++]);
	free(m);
}

char	*ft_check_cmd(char *cmd, const char *path)
{
	char	**path_;
	char	**ref;
	char	*full_cmd;

	path_ = ft_split(path, ':');
	ft_assert(path_ != NULL, "Error(split): split failed for some reason");
	ref = path_;
	while (*path_)
	{
		full_cmd = ft_strjoin(*path_++, cmd);
		if (access(full_cmd, F_OK | X_OK) == 0)
		{
			free(cmd);
			ft_free_matrix(ref);
			return (full_cmd);
		}
		free(full_cmd);
	}
	free(cmd);
	ft_free_matrix(ref);
	return (NULL);
}

char	**ft_parse_cmd(char *cmd, const char *path)
{
	char	**parsed;
	char	*command;

	parsed = ft_strsparse(cmd, ' ', '\'', '\'');
	if (parsed[0][0] == '/' || (parsed[0][0] == '.' && parsed[0][1] == '/'))
	{
		if (access(parsed[0], F_OK | X_OK) == 0)
			return (parsed);
	}
	command = ft_check_cmd(ft_strjoin("/", parsed[0]), path);
	if (command)
	{
		free(parsed[0]);
		parsed[0] = command;
		return (parsed);
	}
	ft_free_matrix(parsed);
	ft_assert(0, strerror(errno));
	return (NULL);
}

int	ft_run_piped(int fd[2], char **cmd, char *env[])
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		execve(cmd[0], cmd, env);
		return (0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	return (status);
}
