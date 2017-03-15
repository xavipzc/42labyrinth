# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 18:25:13 by xpouzenc          #+#    #+#              #
#    Updated: 2017/03/14 17:54:34 by PZC              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC = clang
CFLAGS = -Wall -Wextra -Werror

# BINARY
NAME = wolf3d

#DIRECTORIES
SRCDIR = sources
OBJDIR = objs
INCDIR = includes\
		 /usr/X11/include\
		 libft/includes\

# SOURCES
SRCS = \
		main.c \
		init.c \
		raycast.c \
		draw.c \
		hooks.c \
		colors.c \
		utils.c

OBJS = $(SRC:.c=.o)

# PREFIXES
MLIBX =	-L/usr/X11/lib -lmlx -lm -framework OpenGL -framework AppKit
LIBFT = -Llibft/ -lft

# PATHS FOREACH
OBJP = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
INCP = $(foreach dir, $(INCDIR), -I$(dir))

# COLORS
NOC = \033[0m
OKC = \033[32m
ERC = \033[31m
WAC = \033[33m

# **************************************************************************** #

# RULES

all: $(NAME)

$(NAME): $(OBJP)
	@make all -C libft/
	@echo "\n$(OKC)  [OK] libft.$(NOC)"
	@$(CC) $(CFLAGS) $^ $(INCP) $(LIBFT) -g $(MLIBX) -o $@
	@echo "$(OKC)  [OK] wolf3d binary.$(NOC)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $< $(CFLAGS) -c $(INCP) -o $@
	@echo "$(NOC)  $@ is compiled."

clean:
	@make clean -C libft/
	@echo "$(WAC)[CLEAN] libft directory.$(NOC)"
	@rm -rf $(OBJDIR)
	@echo "$(WAC)  [DEL] objs directory.$(NOC)"
	@echo "$(OKC)   [OK] wolf3d binary.$(NOC)"

fclean:
	@make fclean -C libft/
	@echo "$(WAC)[CLEAN] libft directory.$(NOC)"
	@rm -rf $(OBJDIR)
	@echo "$(WAC)  [DEL] objs directory.$(NOC)"
	@rm -f $(NAME)
	@echo "$(ERC)  [DEL] wolf3d binary.$(NOC)\n"

re: fclean all
