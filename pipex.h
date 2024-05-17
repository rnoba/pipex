/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:00:50 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:31 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define HEREDOC_PATH "/tmp/rnoba-pipex-heredoc"

typedef struct s_pipex {
	int	idx;
	int	piped[2];
	int	in_piped[2];
	int	infd;
	int	heredoc;
}	t_pipex;

void		ft_free_matrix(char **m);

int			ft_run_piped(int fd[2], char **cmd, char *env[]);

char		*ft_check_cmd(char *cmd, const char *path);
char		**ft_parse_cmd(char *cmd, const char *path);

const char	*ft_get_path(char *env[]);
#endif
