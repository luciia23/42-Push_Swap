# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 12:01:22 by lcollado          #+#    #+#              #
#    Updated: 2023/12/20 12:09:34 by lcollado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BIN = bin
DIR_SRC = src

INCLUDE = -I inc
CFLAGS = -g 
CC = gcc $(CFLAGS) $(INCLUDE)
# -fsanitize=address -g3

# ------- LIBFT -------
LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = Makefile
LFLAGS:= -L $(LIBFT_DIR) -lft

# ------- COLORS -------
RED				=	\033[0;31m
GREEN			=	\033[0;32m

SRC = 	push_swap.c\
		utils.c\
		input.c\
		stack_utils.c\
		sorting_utils.c\
		sort.c\
		op_push.c\
		op_swap.c\
		op_rotate.c\
		op_rev_rotate.c\
		push_to_b.c\
		push_to_a.c\
		
OBJS = $(SRC:%.c=$(BIN)/%.o)

# ------- RULES / TRIGGERS
all: $(NAME)

$(NAME) : $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME) 
	@echo "   - $(NAME) ${GREEN}compiled [OK]${GREEN}\n"

$(BIN)/%.o : $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(LIBFT_PATH):
	@cd $(LIBFT_DIR) && make
	@echo "   - LIBFT ${GREEN}compiled [OK]${GREEN}\n"

clean:
	@make -C $(LIBFT_DIR) -f $(LIBFT_MAKE) fclean
	rm -rf $(BIN)

fclean: clean
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY: all re clean fclean