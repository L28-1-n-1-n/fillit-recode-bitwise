# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 18:11:40 by hlo               #+#    #+#              #
#    Updated: 2019/05/04 19:55:10 by hlo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

PATH = -I./includes

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstappend.c ft_print_null.c \
		ft_print.c ft_printi.c ft_char_toupper.c ft_char_toupperi.c \
		ft_print_tab.c ft_lstelemprint.c ft_elem_upper.c ft_lstlength.c \
		ft_lsqrt.c

SRCDIR = srcs
OBJDIR = objs

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

BLACK =	\033[0;30m
RED =	\033[0;31m
GREEN =	\033[0;32m
YELLOW =\033[0;33m
BLUE =	\033[0;34m
PURPLE =\033[0;35m
CYAN =	\033[0;36m
WHITE =	\033[0;37m
RESET=	\033[0m

.PHONY : clean fclean re all

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(CYAN)libft.a has now been built.\n$(RESET)"

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(PATH) -o $@ -c $^

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "$(GREEN)All object files in libft are now deleted\n$(RESET)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(YELLOW)All object and library files in libft are now deleted\n$(RESET)"

re: fclean all

.PHONY: clean fclean re
