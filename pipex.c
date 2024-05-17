/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:01:18 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/17 17:58:40 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <pipex.h>

int	ft_check_heredoc(char *input)
{
	if (0 == ft_strncmp(input, "here_doc", ft_max(ft_strlen(input), 8)))
		return (1);
	return (0);
}

void	ft_handle_heredoc(char *limiter)
{
	char	*line;
	int		fd;

	fd = open(HEREDOC_PATH, O_RDWR | O_TRUNC | O_CREAT, 0644);
	ft_assert(fd != -1, "Error opening here_doc");
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, limiter,
				ft_max(ft_strlen(line) - 1, ft_strlen(limiter))) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd);
}

void	ft_run_side_cmd(char *str, char *envp[], int infd, int outfd)
{
	char	**cmd;
	int		input[2];

	input[0] = infd;
	input[1] = outfd;
	cmd = ft_parse_cmd(ft_strdup(str), ft_get_path(envp));
	ft_run_piped(input, cmd, envp);
	ft_free_matrix(cmd);
}

void	ft_cmd_loop(t_pipex p, char *av[], int ac, char *envp[])
{
	pipe(p.piped);
	ft_run_side_cmd(av[p.idx++], envp, p.infd, p.piped[1]);
	while (p.idx < ac - 1)
	{
		pipe(p.in_piped);
		ft_run_side_cmd(av[p.idx++], envp, p.piped[0], p.in_piped[1]);
		dup2(p.in_piped[0], p.piped[0]);
	}
	if (p.heredoc)
	{
		ft_run_side_cmd(av[ac - 1], envp, p.piped[0],
			open(av[ac], O_RDWR | O_APPEND | O_CREAT, 0644));
		unlink(HEREDOC_PATH);
	}
	else
	{
		ft_run_side_cmd(av[ac - 1], envp, p.piped[0],
			open(av[ac], O_RDWR | O_TRUNC | O_CREAT, 0644));
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipex	p;

	ft_assert(ac >= 5,
		"Usage: ./pipex infile <cmd1> <cmd2> ... outfile");
	p.heredoc = ft_check_heredoc(av[1]);
	if (p.heredoc)
	{
		ft_assert(ac-- >= 6,
			"Usage: ./pipex here_doc LIMITER <cmd1> <cmd2> ... outfile");
		ft_handle_heredoc(av[2]);
		ft_assert(access(HEREDOC_PATH, F_OK | R_OK) == 0, strerror(errno));
		p.infd = open(HEREDOC_PATH, O_RDONLY);
		p.idx = 3;
	}
	else
	{
		ac--;
		ft_assert(access(av[1], F_OK | R_OK) == 0, strerror(errno));
		p.infd = open(av[1], O_RDONLY);
		p.idx = 2;
	}
	ft_cmd_loop(p, av, ac, envp);
	close(p.infd);
}
