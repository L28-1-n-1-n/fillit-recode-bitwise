# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlo <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 18:11:40 by hlo               #+#    #+#              #
#    Updated: 2019/05/08 19:51:47 by hlo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes

SRCS = main.c define_blocks.c read_blocks.c solveboard.c gen_board.c

HEAD = fillit.h

LIBFT = libft/libft.a

HEADP = $(addprefix $(INCDIR)/, $(HEAD))
OBJP = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCP = $(foreach dir, $(INCDIR), -I$(dir))

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

all: $(LIBFT) $(OBJDIR) $(NAME)

re: fclean all

$(LIBFT):
	make all -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADP)
	    $(CC) $(FLAGS) -c -o $@ $< -I$(LIBFT) $(INCP)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@make clean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@echo "$(GREEN)All object files in fillit are now deleted\n$(RESET)"

fclean:
	@make fclean -C libft/
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(NAME)
	@echo "$(YELLOW)All object and binary files in fillit are now deleted\n$(RESET)"

$(NAME): $(LIBFT) $(OBJP)
	$(CC) $(FLAGS) -o $@ $^ -I$(LIBFT)
	@echo "$(RED)fillit has now been built.\n$(RESET)"
