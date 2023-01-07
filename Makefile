# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 21:02:36 by mmoramov          #+#    #+#              #
#    Updated: 2023/01/07 21:15:41 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap.a
HEADER = push_swap.h
C_FLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
SRC_LIBFT = libft/libft.a 
MAKE_LIBFT = make -C libft

# Colors
BLACK = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES = push_swap

SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

all: make_libs $(NAME)

make_libs: 
	@$(MAKE_LIBFT)

-include ${DEP}

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME):: $(OBJ) ./$(SRC_LIBFT)
	cp $(SRC_LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)
	@echo "$(BLUE)Everything has been compilated.$(BLACK)"

$(NAME)::
	@echo "$(BLUE)No actions needed.$(BLACK)"

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ) $(DEP)
	$(MAKE_LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LIBFT) fclean
	@echo "$(MAGENTA)Everything has been cleaned.$(BLACK)"
	
re: fclean all

