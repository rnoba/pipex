#include "libft.h"

typedef struct s_block {
	char	*tok;
	char	*ref;
	char	*tok_ref;
	char	*ref_ref;
	char	**block;
	int		insideBlock;
}	t_block;

static int	ft_parse_inside_block(t_block *b, char close)
{
	if (!b->insideBlock)
		return (0);
	if (*b->tok++ == close)
		b->insideBlock = 0;
	return (1);
}

static int	ft_parse_outside_block(t_block *b, char open)
{
	if (*b->tok != open)
		return (0);
	b->insideBlock = 1;
	(b->tok)++;
	return (1);
}

static t_block	ft_init_block(char	*str)
{
	t_block	b;

	b = (t_block){
		.block = malloc(sizeof(char *)),
		.tok = str,
		.ref = str,
		.tok_ref = str,
		.insideBlock = 0
	};
	return (b);
}

char	**ft_strsparse(char *str, char delimit, char open, char close)
{
	t_block	b;
	int		idx;

	b = ft_init_block(ft_strtrim(str, " "));
	idx = 0;
	while (*b.tok)
	{
		if (ft_parse_inside_block(&b, close))
			continue ;
		if (ft_parse_outside_block(&b, open))
			continue ;
		if (*b.tok == delimit)
		{
			*b.tok++ = '\0';
			b.block = ft_realloc(b.block, sizeof(char *) * idx, sizeof(char *) * (idx + 2));
			b.block[idx++] = ft_strdup(b.ref);
			b.ref = b.tok;
			continue ;
		}
		b.tok++;
	}
	if (*b.ref)
	{
		b.block = ft_realloc(b.block, sizeof(char *) * idx, sizeof(char *) * (idx + 2));
		b.block[idx] = ft_strdup(b.ref);
	}
	free(str);
	free(b.tok_ref);
	return (b.block);
}
