# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 21:02:36 by mmoramov          #+#    #+#              #
#    Updated: 2023/04/15 13:20:45 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
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

SRC_PUSH_SWAP = push_swap.c
SRC_CHECKER = checker.c
SRC_FILES = ft_lst ft_lst2 ft_moves ft_moves2 ft_checks ft_sort ft_utils
SRC = $(addsuffix .c, $(SRC_FILES))

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_CHECKER:.c=.o) 

DEP_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.d) 
DEP = $(SRC:.c=.d)
DEP_BONUS = $(SRC_CHECKER:.c=.d)

all: make_libs $(NAME)

make_libs: #TODO NOT WORKING FOR BONUS
	@$(MAKE_LIBFT)

-include ${DEP_PUSH_SWAP} ${DEP} 

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME):: $(OBJ_PUSH_SWAP) $(OBJ) ./$(SRC_LIBFT)
	$(CC) $(C_FLAGS) $(^) -o $(NAME)
	@echo "$(BLUE)Everything has been compilated.$(BLACK)"

$(NAME)::
	@echo "$(BLUE)No actions needed.$(BLACK)"

-include ${DEP_BONUS}

bonus:: $(OBJ) $(OBJ_BONUS) ./$(SRC_LIBFT)
	touch $@
	$(CC) $(C_FLAGS) $(^) -o $(NAME_BONUS)
	@echo "$(GREEN)Everything has been compilated.$(BLACK)"

bonus::
	@echo "$(GREEN)No actions needed.$(BLACK)"


.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ_PUSH_SWAP) $(OBJ) $(OBJ_BONUS) $(DEP_PUSH_SWAP) $(DEP) $(DEP_BONUS)
	$(MAKE_LIBFT) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) bonus
	$(MAKE_LIBFT) fclean
	@echo "$(MAGENTA)Everything has been cleaned.$(BLACK)"

re: fclean all

