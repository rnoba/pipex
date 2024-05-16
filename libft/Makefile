# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnogueir <rnogueir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 14:33:29 by rnogueir          #+#    #+#              #
#    Updated: 2024/04/23 18:21:12 by rnogueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
PT1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
PT2 = ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c \
	 ft_putendl_fd.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c
EXTRA = ft_strsparse.c ft_realloc.c ft_assert.c ft_strlchr.c ft_strfchr.c ft_isspace.c ft_min.c ft_max.c ft_clamp.c
GNL = get_next_line.c get_next_line_utils.c
BONUS = ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c \
	 ft_lstnew.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
B_OBJ = $(BONUS:.c=.o)
OBJ = $(PT1:.c=.o) $(PT2:.c=.o) $(GNL:.c=.o) $(EXTRA:.c=.o)

all:	$(NAME) 

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(B_OBJ)

bonus: $(B_OBJ)
	$(AR) $(NAME) $(B_OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
