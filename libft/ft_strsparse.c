/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnogueir <rnogueir@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:45:40 by rnogueir          #+#    #+#             */
/*   Updated: 2024/05/17 16:58:23 by rnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

typedef struct s_block {
	char	*tok;
	char	*ref;
	char	*tok_ref;
	char	*ref_ref;
	char	**block;
	int		inside_block;
	int		idx;
}	t_block;

static int	ft_parse_inside_block(t_block *b, char close)
{
	if (!b->inside_block)
		return (0);
	if (*b->tok++ == close)
		b->inside_block = 0;
	return (1);
}

static int	ft_parse_outside_block(t_block *b, char open)
{
	if (*b->tok != open)
		return (0);
	b->inside_block = 1;
	(b->tok)++;
	return (1);
}

static int	ft_handle_delimit(t_block *b, char delimit)
{
	if (*b->tok == delimit)
	{
		*b->tok++ = '\0';
		b->block = ft_realloc(b->block, \
			sizeof(char *) * b->idx, sizeof(char *) * (b->idx + 2));
		b->block[b->idx++] = ft_strdup(b->ref);
		b->ref = b->tok;
		return (1);
	}
	return (0);
}

static t_block	ft_init_block(char	*str)
{
	t_block	b;

	b = (t_block){
		.block = malloc(sizeof(char *)),
		.tok = str,
		.ref = str,
		.tok_ref = str,
		.inside_block = 0,
		.idx = 0
	};
	return (b);
}

char	**ft_strsparse(char *str, char delimit, char open, char close)
{
	t_block	b;

	b = ft_init_block(ft_strtrim(str, " "));
	while (*b.tok)
	{
		if (ft_parse_inside_block(&b, close))
			continue ;
		if (ft_parse_outside_block(&b, open))
			continue ;
		if (ft_handle_delimit(&b, delimit))
			continue ;
		b.tok++;
	}
	if (*b.ref)
	{
		b.block = ft_realloc(b.block, \
				sizeof(char *) * b.idx, sizeof(char *) * (b.idx + 2));
		b.block[b.idx] = ft_strdup(b.ref);
	}
	free(str);
	free(b.tok_ref);
	return (b.block);
}
