# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algultse <algultse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 15:51:43 by algultse          #+#    #+#              #
#    Updated: 2024/03/15 15:22:56 by algultse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft/
SRCDIR = ./srcs/
INCDIR = ./include/
OBJDIR = ./obj/

SRC = check.c error.c free.c init.c list.c list_ops.c list_utils.c push_swap.c \
	push.c rotate_rev.c rotate.c swap.c data_utils.c sort_to_five.c chunk.c \
	neighbour.c main.c
OBJS = $(SRC:%.c=$(OBJDIR)%.o)

LIBFT = -L$(LIBFTDIR) -lft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

test_rand_3:
	@ARG=$$(shuf -i 1-3 -n 3 | tr '\n' ' '); \
	./push_swap $$ARG

test_rand_5:
	@ARG=$$(shuf -i 1-5 -n 5 | tr '\n' ' '); \
	./push_swap $$ARG

test_rand_100:
	@ARG=$$(shuf -i 1-100 -n 100 | tr '\n' ' '); \
	./push_swap $$ARG

test_rand_500:
	@ARG=$$(shuf -i 1-500 -n 500 | tr '\n' ' '); \
	./push_swap $$ARG

.PHONY: all clean fclean re